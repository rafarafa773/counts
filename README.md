## counts website
i only did this to see how to use crow \
i found it really funny \
i should do this more times 

<img width="150" height="150" alt="wohoo" src="https://github.com/user-attachments/assets/38461502-c448-4a8d-9ea1-bafe44a8ddbe" />



if you want to compile (you wont lol) you will have to download crow and gmp \
in gentoo linux its
```
sudo emerge --ask dev-libs/gmp
sudo emerge dev-libs/boost net-libs/asio
git clone https://github.com/CrowCpp/Crow
cd Crow
cmake . -B build -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF
sudo cmake --install build
``` 
and to compile use make 
```
make
./server
```
