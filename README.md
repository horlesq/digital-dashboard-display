
# Digital Dashboard Display

A C++ application using SFML to create a digital dashboard display that simulates a vehicle speedometer and tachometer. This project allows users to visualize speed and RPM levels dynamically, with responsive controls for acceleration and braking. 

![image](https://github.com/user-attachments/assets/ef0d60e4-374c-4fdd-bcc4-c1a336d22f2b)


## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Technologies](#technologies)
- [Installation](#installation)
- [License](#license)
- [Contact](#contact)


## Features

- **Speedometer**: A visual speedometer displaying the current speed, ranging from 0 to 200 km/h.
- **Tachometer**: Simulated RPM indicator, automatically scaling with speed.
- **Interactive Pedals**: Users can accelerate and brake using on-screen pedal buttons.
- **Keyboard Control**: Accelerate and brake using arrow keys for more immersive control.

## Usage

- **Arrow Keys**: _Up Arrow_ - accelerate and increase speed; _Down Arrow_ - Brake and reduce speed.
- **Mouse Controls**: _Click on Accelerator Pedal_ - Increase speed; _Click on Brake Pedal_: Reduce speed

## Technologies

- **Programming Language**: C++
- **Graphics Library**: SFML 

## Installation

To get started with this project, follow these steps:
1. **Clone the repository**:
```bash
git clone https://github.com/horlesq/digital-dashboard-display.git
```
2. **Navigate to the project directory**:
```bash
cd city-breaks-diary/digital-dashboard-display
```
3. **Install SFML:**:
Follow the instructions for your operating system at [SFML Installation Guide](https://www.sfml-dev.org/tutorials/2.6/start-vc.php)
4. **Build the project**:
   Link SFML to your compiler and build the application:
```bash
g++ -o dashboard main.cpp Dashboard.cpp Speedometer.cpp Tachometer.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
5. **Run the executable**:
 ```bash
./dashboard
```


## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contact

For any inquiries or feedback, feel free to reach out via:

- Email: adrian.horlescu@gmail.com
- Linkedin [Adrian Horlescu](https://www.linkedin.com/in/adrian-horlescu/)
- GitHub: [Horlesq](https://github.com/horlesq)
