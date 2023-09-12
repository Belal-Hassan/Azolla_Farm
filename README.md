<a name="readme-top"></a>
<hr>
<br />
<div align="center">
  <a href="https://github.com/BelalHassan7/Azolla_Farm">
  </a>
<h3 align="center">Azolla Farm</h3>
  <p align="center">
    <br />
    <a href="https://github.com/BelalHassan7/Azolla_Farm"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/BelalHassan7/Azolla_Farm">View Demo</a>
    ·
    <a href="https://github.com/BelalHassan7/Azolla_Farm/issues">Report Bug</a>
    ·
    <a href="https://github.com/BelalHassan7/Azolla_Farm/issues">Request Feature</a>
  </p>
</div>
<hr>


<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#About-The-Project">About The Project</a>
      <ul>
        <li><a href="#Built-With">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#Functionss">Functions</a>
    </li>
    <li><a href="#Contact">Contact</a></li>
  </ol>
</details>

## About The Project
The Azolla Farm project is controlled by an Arduino Nano board. Since the Azolla plant is grown on a water surface and is sensitive to UV-B radiation, 
the main controlled growth conditions of the Azolla plant are the water temperature and UV radiation exposure. When the water temperature sensor gets
a reading below or over the average temperature for the Azolla, the cooling and heating proecess starts to take place using a Thermoelectric Cooler (TEC).
In addition, when the UV sensor gets a UV-B radiation reading, two servo motors cover the plant's container by a reflective Aluminum sheet.

### Built With

* [![arduino][arduino.js]][arduino-url]
<p align="right">(<a href="#readme-top">back to top</a>)

## Functions

* `float temp()` returns water temperature.

* `void heat()` heats the water.

* `void cool()` cools the water.

* `void stop()` stops adjusting the temperature.

* `float UVindex()` returns the UV irradiance on the UV index scale.

* `void cover()` covers the Azolla container.

* `void uncover()` uncovers the Azolla container.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

Belal - belal.34327@gmail.com

Project Link: [https://github.com/BelalHassan7/Azolla_Farm](https://github.com/BelalHassan7/Azolla_Farm.git)
<p align="right">(<a href="#readme-top">back to top</a>)</p>

[arduino.js]: https://img.shields.io/badge/Arduino-00878F?logo=arduino&logoColor=fff&style=flat
[arduino-url]: https://www.arduino.cc
[esp.js]: https://img.shields.io/badge/Espressif-E7352C?logo=espressif&logoColor=fff&style=flat
[esp-url]: https://www.espressif.com
[fb.js]: https://img.shields.io/badge/Firebase-FFCA28?logo=firebase&logoColor=000&style=flat
[fb-url]: https://firebase.google.com
