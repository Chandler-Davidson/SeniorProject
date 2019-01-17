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
#### Documents
#### Demonstrations

## List of Milestones

## Personnel
| Role  | Person |
| ----------- | ----------- |
| Software Lead  | Chandler Davidson |
| Requirements Analyst | Snehal Gaikwad |
| Scrum Master | Robert Harvey |
| Customer Liaison | Elijah Hicks |

## Risks