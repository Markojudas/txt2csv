<!-- markdownlint-disable -->

# txt-to-csv File Conversion 

## About
This is a very simple and naive program written in C that converts a space/tab separated values text file into a comma separated (csv) file and back, very straightforward.

This program was written as class project for a Systems Programming course, while learning the basics of the C programming language. The original code converted files from CSV to several made-up format and back. 

I needed to convert a txt file to csv for another project and for some reason this project came to mind first before searching Google. The program now has been refactored and cleaned up.
<br>
<br>

## Requirements

You will need a C compiler on your system. Must Linux distros and, I believe, macOS (or other UNIX system) come already with a C compiler ready to use.
<br>

Windows:
<ul>
    <li><a href="https://www.digitalocean.com/community/tutorials/c-compiler-windows-gcc">Install C Compiler on Windows</a></li>
    <li>or, install the <a href="https://visualstudio.microsoft.com/vs/features/cplusplus/">C/C++ Development Support for Visual Studio</a>
</ul>
<br>

File Format:

<ul>
    <li>.CVS: comma-separated values</li>
    <li>.TXT: space/tab separated values (^[a-zA-Z0-9]\t*\n*)</li> 
</ul>
<br>
<br>

## Run

You can simply run the application directly from Visual Studio (if on windows) or you could use the **Developer Command Prompt for VS/Developer PowerShell for VS** that comes with Visual Studio (not sure since which release but definitely on 2022)

<pre><code>cl .\txt2csv.c
.\txt2csv.exe</pre></code>

Linux/macOS:
<pre><code>gcc -o txt2csv txt2csv.c
./txt2csv</code></pre>

