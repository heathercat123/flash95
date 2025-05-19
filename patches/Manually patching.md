1. Open Adobe Flash in an hex editor such as HXD
2. Search for KERNEL32
3. Replace it by CORKEL32
4. Search for USER32
5. Replace it with CORUSR
You may stop here, but you'd need JHRobotics' SIMD95 or a similar patch to run it on MMX-compatible cpus.

6. Search for these bytes: 7445b8000000000fa2
     Note: It may also work by searching for 745dc745ec040000009c588bc8
7. Replace 74 by EB
8. Enjoy!