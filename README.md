# 🏥 Hospital Management System (C++ OOP Project)

A console-based Hospital Management System built using Object-Oriented Programming (OOP) principles in C++. This project was designed to simulate real-world hospital operations like doctor and patient registrations, appointments, login systems, medical history tracking, and doctor notes — all organized using modular code across multiple `.h` and `.cpp` files.

---

## 📌 Features

- 👨‍⚕️ **Doctor Module**
  - Register a new doctor
  - Set available time slots
  - View profile and appointed patients
  - Write prescriptions and notes for patients

- 🧑‍🦰 **Patient Module**
  - Register a new patient with medical history
  - View all available doctors
  - Book appointments
  - View profile including doctor notes

- 🔐 **Login System**
  - Doctors and patients can securely log in using ID and password
  - Basic validation to ensure authorized access

- 🔁 **Menu-Based Console Interaction**
  - Intuitive prompts and user flow
  - Looping structure for continuous use until user exits

---

## 💡 Technologies & Concepts Used

- C++ OOP (Classes, Inheritance, Abstraction, Virtual Functions)
- STL (`vector`, `string`)
- Modular programming (separated `.h` and `.cpp` files)
- Dynamic memory and object handling
- Console input/output and interaction
- Simple access control (login authentication)

---

## 📁 File Structure

Hospital-Management-System/
│
├── main.cpp
├── Person.h
├── Doctor.h
├── Doctor.cpp
├── Patient.h
├── Patient.cpp
├── Hospital.h
├── Hospital.cpp
├── README.md ← (you are here)


> `Person` is an abstract class. `Doctor` and `Patient` inherit from it.

---

## 🚀 How to Run

1. Clone this repository or download the source code.
2. Compile using any C++ compiler that supports C++11 or higher.
3. Run the executable.

Example with `g++`:
```bash
g++ main.cpp Doctor.cpp Patient.cpp Hospital.cpp -o hospital_system
./hospital_system


What I Learned
Deep understanding of Object-Oriented Programming in C++

Structuring multi-file projects cleanly

Practical use of STL containers

Building interactive CLI-based systems

Error handling and input validation

📈 Future Improvements
File I/O for persistent data storage

Admin module to view analytics

Use unordered_map for faster patient/doctor lookups

Better UI with colors and formatting

GUI version using Qt or another framework

🤝 Contribution
This is a solo project built for learning purposes. However, feel free to fork it, suggest improvements, or use it as a reference for your own OOP practice.

#📧 Contact
#Made by Huzefa Javed
#🧠 1st-semester Software Engineering student with a passion for backend development and system design.
#📬 Huzefahjaved@gmail.com