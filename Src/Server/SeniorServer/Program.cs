using System;
using System.Runtime.InteropServices;
using Nancy.Hosting.Self;

namespace SeniorServer
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var hostConfigs = new HostConfiguration
            {
                UrlReservations = new UrlReservations
                {
                    CreateAutomatically = true
                }
            };

            const string url = "http://localhost:8080";

            using (var host = new NancyHost(hostConfigs, new Uri(url)))
            {
                host.Start();
                Console.WriteLine($"Running on {url}");
                Console.ReadLine();
            }
        }
    }
}