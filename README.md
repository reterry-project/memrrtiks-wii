# memrrtiks, suashem: Wii Edition

This is the source code release of the Wii port of the 2010 freeware Flash game "memrrtiks, suashem", by Terry Cavanagh.


## Download

**If you are not photosensitive, you can download the port of the game [here](https://reterry.uk/memrrtiks-wii.zip)**. 
Otherwise, **DO NOT PLAY** this game as it may give you seizures.

Plans for it to be in the Open Shop Channel are underway, but as for the moment the only way to obtain it is through the above link.

**If you are not photosensitive, and want the original release, it is playable on [Kongregrate](https://www.kongregate.com/en/games/TerryCavanagh_B/memrrtiks-suashem)**.
Again, if you are photosensitive, **DO NOT PLAY** this game as it has a high risk of giving you a seizure.


## Q&A
### Why?
I wanted to try and see how hard it would be to port a Flash game to the Wii.

I was going to do one of my favorite games, Don't Look Back, but had second thoughts that the game might be a bit too complicated to port (I had made an attempt to port it to HTML5+JS earlier, and couldn't even make it past the loading screen!)

So I decided on another game that I presumptuously assumed would be much simpler: a 2D indie shootemup called memrrtiks, suashem, by the same author of DLB.

Turns out I was very wrong and they would have been almost exactly the same difficulty to port, lol...

But here we are today, and the source code is in your hands!

### How?
I had a LOT of free time on my hands.

If you want the real technical explaination, you can read this Reddit comment:

> I used the FFdec compiler to decompile the ActionScript and then ported that to C++. Used libogc for the graphics and audio and experience for the actual conversion of AS3 to C++.
>
> Used a lot of ActionScript reference to help and some code from open source flash alternatives (openfl) for accurate collision detection.
>
> Took me about a week to make. ALWAYS test your homebrew in Dolphin first unless you want to crash your Wii, as when writing in C/++ you're always prone to memory corruption 

(r/WiiHacks, https://www.reddit.com/r/WiiHacks/comments/1qxwozo/comment/o413swb)

### Is this source code released with permission?
Yes! I emailed the author of the game and he replied, saying that I had his permission to do what I wanted with the source code.

I am very grateful that he let me do this, because he could have said no or even asked me to take the binary down!

If you're reading this, thanks Terry! :)

### License?
This port of the game is BSD3. You are free to fork it and make it into whatever you please.
As for the original source code, you will have to ask the original author.

### Where are the commits?
I WOULD have open sourced the entire repository, but it contains raw ActionScript source code along with some SWFs for reference.

While SOME of that raw decompiled source is retained in `gfx.cpp`, as the functions go unused, it just doesn't feel right to distribute along with the port.

### I want to give you my money!
Donate to Terry Cavangh instead through buying Terry's Other Games on [Steam](https://store.steampowered.com/app/2824580/Terrys_Other_Games) or [GOG](https://terrycavanagh.itch.io/terrys-other-games)!

It's a neat little package holding a dozen or so remasters of his old games.
Now you can play memrrtiks, suashem in CLEAN 60FPS like a true PC gamer... ;)

Personally, I do not want to make money out of what is essentially his game, and that's why I encourage you to donate to him instead.

### I have a friend with epilepsy, can I play this game with him?
No! I **STRONGLY** recommend against it. I know I can't stop you, but I'd like to say that **YOU HAVE BEEN WARNED** if any incidents occur.

