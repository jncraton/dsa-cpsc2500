---
reading: '[The Basic Reproducible Workflow Template](http://www.practicereproducibleresearch.org/core-chapters/3-basic.html)'
teaching_goal: Students will understand the core principles and stages of a reproducible research workflow.
learning_objectives:
  - Identify the three key practices of reproducible research
  - Describe the three main stages of a reproducible workflow
  - Explain the importance of automation and controller scripts
  - Outline a standard project directory structure
---

# Reproducible Workflows

## Definition

Computational reproducibility is the ability for another researcher to recreate research outputs from provided data, code, and documentation

## Core Practices

- Separate, label, and document all data and files
- Document all operations fully and automate them
- Design workflows as a sequence of small, glued steps

## Why Reproducibility?

- Ensures integrity of scientific results
- Allows others to verify findings
- Facilitates collaboration and building on work

## Workflow Stages

- Data Acquisition
- Data Processing
- Data Analysis
- Automation

## Stage 1: Acquisition

- Collecting raw data from primary sources
- Web-scraping or simulations
- Result: Raw data files

## Data Storage

- Use plain text formats (e.g., CSV)
- Avoid proprietary formats (e.g., XLSX)
- Use descriptive, space-free filenames

## Stage 2: Processing

- Cleaning, filtering, and subsetting raw data
- Record every step in a script
- Avoid manual edits in data files

## Processing Logic

- Scripts should read raw data
- Scripts should save to a new location
- Never overwrite original raw data

## Stage 3: Analysis

- Perform statistics, visualizations, or modeling
- Use scripts to ensure exact replication
- Save all outputs (figures, tables) to results

## Automation

- Create a controller script (e.g. makefile)
- Execute all stages with one command

## Verification

- Delete intermediate results
- Run controller script
- Verify that results regenerate correctly

## Conclusion

- Reproducibility is a foundational framework
- Start simple and scale
