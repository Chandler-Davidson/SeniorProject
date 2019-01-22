# Software Development Plan

## Project Overview
### Product Usage
The product to be implemented will be a static source code analyzer and quality measurement tool. This tool will be used by software developers for the following:

1. Organizational code uniformity.
2. Detect potential errors.
3. Reduce the cognitive strain of syntactic issues.

### Product Constraints
The tool will analyze compilable, syntactically valid, C++ source and header files. Files of invalid extensions will be ignored.

### Necessary User Input
To effectively run the analysis, the user must select an individual file, multiple files, or directories to analyze. The user is able to toggle the activated rule set and modify their related severity. 

### Typical Data Output
Once run, the analyzer will output any activated rule's warnings or errors, a general code score, and an expandable detailed code metrics section.

#### Coding Errors
Code warnings and errors will include the following:
- The activated rule that was broken.
- The severity of the issue: Warning | Error.
- The associated file name, class, function, and line number.
- An expandable detail view where a buffer of the function will be shown with the offending code highlighted.

#### Coding Score
The coding score will be a general metric used to judge severity of one's source. The range of scores will include: `A, B, C, D,` and `F`. This will be a calculated score based off the general size of code analyzed, the rules broken, and the rule's corresponding severity.

#### Coding Metrics
The coding metrics section will be a detailed look into the Coding Score. It will provide general details of files, function complexity, the number of declarations of unique types, and etc.

## Project Schedule
### List of Deliverables
| Date | Title |
| ---- | ----- |
| January 28th | Software Development Plan Document |
| January 28th | Software Development Plan Presentation |
| February 13th | Project Backlog: First Draft |
| March 4th | Architectural Backlog |
| March 27th | Preliminary GUI Design |
| April 17th | Final Delivery |

### Sprint Reports
| Date | Title |
| ---- | ----- |
| January 30th | Sprint 1 Report |
| February 18th | Sprint 2 Report |
| March 6th | Sprint 3 Report |
| April 1st | Sprint 4 Report |
| April 22nd | Sprint 5 Report |

### List of Milestones
| Date | Title | Description |
| ---- | ----- | ----------- |
| February 4th | Architectural Design | Define the broad systemic program architecture and schemas. |
| February 18th | Minimum Viable: Parser | Implement the basic framework for the parser. Develop one or two rules to demonstrate product viability. |
| March 4th | Minimum Viable: Back-end | Implement the basic framework for the back-end. Develop the connectivity of such using a rudimentary UI. |
| March 11th | Minimum Viable: Front-end | Implement the basic framework for the front-end GUI. Cover the most rudimentary user stories. |
| March 25th | Product Refinement | Refine product features, general code cleaning and improvement. |
| April 1st | Feature Improvement | Add additional feature sets. |
| April 8th | Product Delivery | Finish major customer requests and deliver the final product. |

## Personnel
| Role | Person |
| ---- | ------ |
| Software Lead  | Chandler Davidson |
| Requirements Analyst | Snehal Gaikwad |
| Scrum Master | Robert Harvey |
| Customer Liaison | Elijah Hicks |

## Risks
Below is a listing of acknowledges risks, their potential impact, and their summarized avoidance plans. The impact potentials are ranked from least to worst impacts as the following: `Negligible`, `Marginal`, `Critical`, and `Catastrophic`.

| Potential Risk | Potential Impact | Avoidance Plan |
| -------------- | ---------------- | -------------- |
| Loss of a team member | Critical | Preemptive early deadlines |
| Product size | Critical | Awareness of feature creep |
| Technology stack | Marginal | Individual review and research |