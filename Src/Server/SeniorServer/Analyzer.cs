using System;
using System.Runtime.InteropServices;
using System.Text;

namespace SeniorServer
{
    public static class Analyzer
    {
        private const string DllLocation =
            @"C:\Users\chand\Documents\GitHub\SeniorProject\Src\Debug\SourceCodeChecker.dll";

        public static string RunAnalysis(string rules, string filePaths)
        {
            try
            {
                if (string.IsNullOrEmpty(rules) || string.IsNullOrEmpty(filePaths))
                    throw new Exception("Cannot pass empty rules or file paths.");

                // Pass a StringBuilder to act as a char*
                var resultsSb = new StringBuilder(1024);
                StartAnalysis(resultsSb, rules, filePaths);

                // Convert to string
                return resultsSb.ToString();
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }

            return "";
        }

        [DllImport(DllLocation,
            EntryPoint = "StartAnalysis", CallingConvention = CallingConvention.Cdecl)]
        private static extern void StartAnalysis(StringBuilder str, string rule, string filePaths);
    }
}