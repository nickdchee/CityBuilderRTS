# CloudCity
A small game almost entirely from scratch about population management and city building using openFrameworks written during HackED 2019.

![](https://github.com/nickdchee/CityBuilderRTS/blob/master/readmeImages/ScreenCap1.PNG)
![](https://github.com/nickdchee/CityBuilderRTS/blob/master/readmeImages/ScreenCap2.PNG)

The following was copied from the devpost submission @ https://devpost.com/software/cloudcity.

### Inspiration
I have been playing lots of city builders lately, and I thought developing the mechanics of them from scratch would be quite rewarding, as opposed to developing with a game engine.

### What is it
It's a game about city building and managing a population that increases every 15s in random amounts. You must keep your citizens happy or else you lose! You have a limited amount of room since you are building on a city in the clouds, hence CloudCity.

### How we built it
We used openFrameworks which is an open source C++ library developed mainly for scientific research purposes such as demonstrating algorithms. It is not meant for games and is extremely rarely used for games. However, I like the framework as it has a lot to offer. It still lacks in many basic things so its quite a challenge to use - lots of digging into the source code and finding out how stuff works, and constantly needing to add/change core functionality.

### Challenges we ran into
There was quite a bit of math involved, and while my teammates and I are quite familiar with linear algebra and basic openGL knowledge from CMPUT 350 (games AI programming course), we still had issues. For instance, orthographic projection of a camera is hard to use when trying to have an isometric 3D game. We never got the camera fixed due to the limitations of the framework's camera capabilities.

### Accomplishments that we're proud of
It looks great (I think), and its playable! Some optimizations could be made, but its a neat little game, with nice music. All visual artwork is original.

### What we learned
Lots of math and openGL. Also, we didn't look at all as to how other games solve these simple problems so we were basically blindly reinventing the wheel, such as how a button/UI framework is made, general program structure, tile selection (lots of little nuances), etc.

#### What's next for CloudCity
Add more features like more buildings, building actions (right hand panel stuff), people should be able to starve to death, etc. Classic city builder stuff. I love city builders in that they are easy to expand and add small features to iteratively. Also, add more info about how much buildings cost, events that occurred, etc. 

Remember, this was pretty much all done from scratch! openFrameworks is NOT a game engine, it is basically an advanced openGL wrapper with some nice features here and there.

Note, VS2017 was giving me trouble so I could not compile the release build. If you really want, you could download the openFrameworks plugin for VS2017 and clone the repo. You might have to reinclude the ofxassimpmodelloader. The linker additional dependencies under Input would have to be changed to '%(AdditionalDependencies);assimp32.lib'. 
