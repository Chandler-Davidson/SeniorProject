#pragma once

extern "C" __declspec(dllexport) void StartAnalysis(char* results, char* rules, char* filepaths);

vector<string> split(char *phrase, string delimiter);
