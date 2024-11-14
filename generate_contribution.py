import requests
import datetime
import os

# GitHub 사용자 정보
USERNAME = "eunsoA"
REPO = "1D1A"
TOKEN = os.getenv("GITHUB_TOKEN")  # GitHub Actions에서 환경 변수로 제공

if not TOKEN:
    raise ValueError("Error: GITHUB_TOKEN is not set")

# 특정 날짜 이후의 커밋만 가져오기 (예: 2024-11-04 이후)
FILTER_DATE = "2024-11-04"

# GitHub API를 사용하여 특정 레포지토리의 커밋 기록 가져오기 (페이지네이션 추가)
def get_commit_data(username, repo):
    commits = []
    page = 1

    while True:
        url = f"https://api.github.com/repos/{username}/{repo}/commits"
        headers = {"Authorization": f"Bearer {TOKEN}"}
        params = {"per_page": 100, "page": page}
        response = requests.get(url, headers=headers, params=params)

        if response.status_code != 200:
            print("Error fetching commits:", response.status_code, response.text)
            break

        data = response.json()
        if not data:
            break

        # 커밋 데이터 추가
        commits.extend(data)
        page += 1

    # 특정 날짜 이후의 커밋만 필터링
    filtered_commits = []
    for commit in commits:
        commit_date = commit["commit"]["author"]["date"][:10]  # YYYY-MM-DD 포맷
        if commit_date >= FILTER_DATE:
            filtered_commits.append(commit)

    return filtered_commits

# 커밋 기록을 분석하여 SVG 파일 생성
def generate_svg(commit_data):
    commit_dates = [commit["commit"]["author"]["date"][:10] for commit in commit_data]

    # SVG 파일 생성
    svg_content = f"""
    <svg width="600" height="200" xmlns="http://www.w3.org/2000/svg">
        <rect width="100%" height="100%" fill="white"/>
        <text x="10" y="20" font-family="Arial" font-size="16" fill="black">
            Commit history for [ {REPO} ] repository since {FILTER_DATE}
        </text>
    """
    y_pos = 40
    for date in sorted(set(commit_dates)):
        svg_content += f'<text x="10" y="{y_pos}" font-family="Arial" font-size="14" fill="green">✅ {date}</text>\n'
        y_pos += 20

    svg_content += "</svg>"
    return svg_content

def main():
    commits = get_commit_data(USERNAME, REPO)
    if not commits:
        print("No commits found since", FILTER_DATE)
        return

    svg_content = generate_svg(commits)

    # dist 디렉토리가 없으면 생성
    if not os.path.exists("dist"):
        os.makedirs("dist")

    with open("dist/contribution.svg", "w") as file:
        file.write(svg_content)
    print("SVG file generated: dist/contribution.svg")

if __name__ == "__main__":
    main()
