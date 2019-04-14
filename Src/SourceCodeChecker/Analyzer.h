#pragma once

extern "C" __declspec(dllexport) void SetActiveRules(char* config);

extern "C" __declspec(dllexport) void SetFilePaths(char* config);

extern "C" __declspec(dllexport) int StartAnalysis(char* config);