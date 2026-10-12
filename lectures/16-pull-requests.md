---
reading: [Quickstart for pull requests](https://docs.github.com/en/pull-requests/get-started/pull-request-quickstart)
teaching_goal: Students will understand the lifecycle of a GitHub pull request.
learning_objectives:
  - Identify the purpose of a pull request
  - Create a branch and commit changes
  - Open and manage a pull request
  - Respond to feedback and merge changes
---

# Pull Requests

## Definition

A pull request proposes changes

- Changes occur on a separate branch
- Others review changes before merging
- Keeps the main codebase stable

## Branching

- Create an isolated workspace
- Use a new branch for every feature
- Avoid working directly on main

## CLI Workflow

- Clone the repository
- Change to the directory
- Create and switch branch

```bash
git checkout -b YOUR-BRANCH-NAME
```

## Authoring Code

- Make changes on your branch
- Keep changes focused and simple
- Smaller requests are easier to review

## Committing Changes

- Save work in small snapshots
- Each commit needs a message
- Describe the change clearly

## Local Commit

- Stage your changes
- Commit with a message
- Push to the remote branch

```bash
git add .
git commit -m "Describe change"
git push --set-upstream origin YOUR-BRANCH-NAME
```

## Opening PRs

- Go to the Pull requests tab
- Click New pull request
- Select base and compare branches
- Click Create pull request

## PR Descriptions

- Provide a clear title
- Explain what changed and why
- Use draft status for work in progress

## Addressing Feedback

- Reviewers may suggest changes
- Click Commit suggestion to accept
- Push new commits to update PR
- Mark conversations as Resolved

## Merging Changes

- Ensure reviews and checks pass
- Click Merge pull request
- Confirm the merge
- Delete the head branch

---

Why is it better to use small pull requests instead of one large one?
