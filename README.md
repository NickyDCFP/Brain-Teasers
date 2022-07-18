# Brain-Teasers

### console.cpp
  A brain teaser that showcases some quirks of the Windows system and some badly organized C++ syntax. See if you can figure it out!

<details>
  <summary>Solution (spoiler warning, obviously!) </summary>
  
    First, let's fix the syntax (don't we already have enough problems here to deal with?). After some brief reorganization, 
    shifting, and moving, we get the following:
  
```
#include <fstream>
using namespace std;
const string FILENAME = "\x63\x6f\x6e\x2e\x74\x78\x74";

struct main {
    main(ofstream *const textfile = new ofstream) {
        *textfile = ofstream(FILENAME);
        *textfile << FILENAME;
        delete textfile;
    }
}textfile;

int main() {}
```
  
  
    Now, let's look at the main function, since that's generally where we can find what a program does... but what is this?
    There's nothing there! Does this program do nothing? Hmm, let's continue.
  
    Let's break down the struct main. Here, there's nothing special about the struct being named main; it could just as easily be named
    anything else without changing the program's execution. We're only given a constructor that takes in a constant pointer
    to an ofstream (with a defined default value). This constructor assigns the ofstream the pointer holds to an ofstream(FILENAME),
    opening a file with the name FILENAME. Next, it appends FILENAME to the contents of this ofstream, essentially appending
    the file's name to the file. Then, it deletes the textfile pointer. It's important to note here that the ofstream destructor
    also closes the file the pointer references, saving the changes we've made to it.
  
    Now, the struct's definition is complete, but we have an extra instance of some object textfile here. This textfile object is actually
    an instance of the main struct. You can almost think of it as if we finished the struct definition and then added main textfile;
    on the next line. What this means for our purposes is that, at runtime, an instance of the main struct is created, calling main's
    default constructor, which exists because of the default value for the existing constructor's parameter. That is, at runtime,
    the code in the main struct's constructor will run, so this program does do something!
  
    Finally, we can decipher the meaning of FILENAME. This is simple hex notation, which can be translated, using a 
    hex/ASCII reference, to con.txt.
  
    All together, we can conclude that this program opens a file named con.txt in the working directory and appends con.txt to it.
  
    There's more, though!
  
    Windows systems have an interesting quirk in place for backwards compatibility. You can check out this video by Tom Scott for more 
    information (https://www.youtube.com/watch?v=bC6tngl0PTI), but here's a quick summary.
  
    Essentially, certain filenames in Windows are protected because they denote "device files." That is, a few decades ago, they were an
    interface between the file system and device drivers. For example, if you wanted to print something, you could copy the file to 
    the PRN device file while plugging your printer into the appropriate port on your computer. This meant that, no matter what device
    you used or how complicated its drivers were, you didn't have to deal with any of that, since the driver was designed to interact
    with the device file. As a relic for backwards compatibility, though, these device files are still in place and protected.
  
    Well, coincidentally, CON happens to be a device filename that represents the console. So, in reality, when we tell our program to
    open con.txt, it doesn't create any new file. con.txt exists! It's the console! So, when ran, the program opens con.txt, prints
    con.txt to it, and then closes it. Since, again, con is the console, this program just prints con.txt to the console!
  
</details>
