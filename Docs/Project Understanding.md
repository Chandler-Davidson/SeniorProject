# Project Understanding

## Assumptions
### General Application
- Create a tool that runs against a single file, selected files, or all the files in all sub-directories.
- The majority our tool must be written in C++.
- All code run in the tool will be C++.
- Cross compatible, PC and Mac.
- The resulting application must be portable and able to run without an internet connection.

### Implementation
- User can enable/disable *rules*.
- Only run against files that have changed since the last run OR the rule set has changed.
- Analysis must be available within the file, class, and methods.
- Able to export to CSV.
- Measurement histories must be cached and viewable.
- All code run against will be symatically correct.
- Built in application and coding standard help.

## Customer Questions
- What version of C++?
- What features are a part a minimum viable product?
- What existing software/tooling are we allowed to use?
	- Open source
	- Clang?
	- AST generator?
	- C++ parser?