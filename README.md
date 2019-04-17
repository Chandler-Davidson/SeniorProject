# SeniorProject

Developed for The University of Alabama in Huntsville's CS 499: Senior Project. Further project information and requirements are listed under [Docs](/Docs).

## Team Members

- [Chandler Davidson](https://github.com/chandler-davidson)
- [Elija Hicks](https://github.com/eth0004)
- [Robert Harvey](https://github.com/rkh0005)
- [Snehal Gaikwad](https://github.com/wonder193)

## Project Structure

The entire project is made up of three parts:

- [Backend C++ dll used for analysis](/Src/BackendAnalyzer)
- [C# REST server used for networking](/Src/Server)
- [React/Next.js frontend client](/Src/Client)

## Beginning Development

~~Currently, there is no automated build process; however, it is mostly straightforward.~~

You can use the [.bat file](../Docs) to automatically build the files and start the client

OR 

Manually build it

#### BackendAnalyzer

1. Open `SourceCodeChecker.sln`.
2. Build the solution!

#### Server

1. Open `SeniorServer.sln`.
2. Right click `References` within `Solution Explorer`.
3. Select `Manage Nuget Packages`.
4. In the top right, select `Restore Missing Packages`.
5. Build the solution!

#### Client

1. Open the `Client/` directory using a CLI.
2. Run the command `npm install`, this will install all dependencies.
3. Once installed, run `npm run dev`.
4. Open a browser to `localhost:3000`.
5. Have fun!
