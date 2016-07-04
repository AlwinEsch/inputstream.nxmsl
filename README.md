# inputstream.nxmsl (1.0.0)

This is a dash mpd file addon for kodi's new InputStream Interface.

- this addon is part of the official kodi repository and part of each kodi installation

##### Decrypting:
Decrypting is not implemented. But it is prepared!  
Decrypting takes place in separate decrypter shared libraries, wich are identified by the inputstream.nxmsl.licensetype listitem property.  
Only one shared decrypter library can be active during playing decrypted media. Building decrypter libraries do not require kodi sources.  
Simply check out the sources of this addon and you are able to build decrypters including full access to existing decrypters implemented in bento4.

##### Bandwidth and resolution:
When using inputstream.nxmsl the first time, the selection of stream quality / stream resolution is done with a guess of 4MBit/s. This default value will be updated at the time you watch your first movie by measuring the download speed of the media streams.  
Always you start a new video, the average bandwidth of the previous media watched will be taken to calculate the initial stream representation from the set of existing qualities.  
If this leads to problems in your environment, you can override / adjust this value using Min. bandwidth in the inputstream.nxmsl settings dialog. Setting Min. bandwidth e.g. to 10.000.000, the media selection will never be done with a bandwidth value below this 
value.  
Currently the complete media is played with the selection from this initial step, adaptive stream changes during a running video is still under development.  
There is a new Max. resolution select field in the inputstream.nxmsl settings dialog.
Auto will select the best resolution matching to your videoplayer display rect without any limits.
If your display resolution is 720p, you will not be able to watch 1080p videos if there are video representations available closer to 720p.  


##### TODO's:
- Adaptive bitrate switching is prepared but currently not yet activated  
- Automatic / fixed video stream selection depending on max. visible display rect (some work has to be done at the inputstream interface).
- Currently always a full segment is read from source into memory before it is processed. Reading in smaller chunks could be lead to faster start of the media and better cache fill strategy.

##### Notes:
- This addon is single threaded. The memory consumption is the sum of a single segment from each stream currently playing (will be reduced, see TODO's) Refering to known streams it is < 10MB for 720p videos.

##### Credits:
[@fernetmenta](github.com/fernetmenta) Best support I ever got regarding streams / codecs and kodi internals.  
[@notspiff](https://github.com/notspiff) Thanks for your ideas / tipps regarding kodi file system  
[bento4 library](https://www.bento4.com/) For me the best library choice for mp4 streams. Well written and extensible!

##### Continuous integration:
[Travis CI build state:](https://travis-ci.org/mapfau) ![alt tag](https://travis-ci.org/mapfau/inputstream.nxmsl.svg?branch=master)  
