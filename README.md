# school_system
 The Student Management System is a C-based program to manage students, courses &amp; professors. It allows adding, deleting &amp; viewing student details, courses &amp; prof profiles. Data is persisted in text files. It includes a basic login system &amp; offers functionalities based on user roles.
# Student Management System - Readme

## Introduction
This C program implements a simple student management system with features to manage student, course, and professor information. The program reads and writes data to external text files for persistent storage. It includes a basic login system to differentiate between students and professors and provides different functionalities based on the user type.

## Features
The Student Management System includes the following features:

1. Add Student: Allows administrators to add new student information, including first name, last name, student ID number, field of study (minor), and password.

2. Delete Student: Administrators can remove a student from the system using their student ID number.

3. Add Course: Administrators can add new course information, including course code, course name, and course point.

4. Delete Course: Administrators can delete a course from the system using the course code.

5. Add Professor: Administrators can add new professor information, including first name, last name, professor code, field of teaching (minor), role, and password.

6. Assign Course to Professor: Administrators can assign courses to professors, indicating which professor is teaching which course.

7. View Student Information: Students can view their own information, including name, last name, student ID number, field of study, and password.

8. Add Course to Student: Students can add courses to their profile, subject to certain conditions (total points between 14 and 17).

9. View Student's Enrolled Courses: Students can view the courses they have enrolled in.

10. View Professor Information: Professors can view their own information, including name, last name, professor code, field of teaching, role, and password.

11. View Professor's Assigned Courses: Professors can view the courses they are assigned to teach.

## Data Persistence
The program uses external text files for data persistence. The following files are used to store data:

1. `student.txt`: Contains student information, including first name, last name, student ID number, and field of study.
2. `courses.txt`: Contains course information, including course code, course name, and course point.
3. `prof.txt`: Contains professor information, including first name, last name, professor code, field of teaching, and role.
4. `auth.txt`: Contains authentication information for students, including student ID number and password.
5. `authp.txt`: Contains authentication information for professors, including professor code and password.
6. `studentc.txt`: Contains information about courses that students have added.
7. `teacherc.txt`: Contains information about courses assigned to professors.

## Login System
The program includes a basic login system to differentiate between students and professors. Users are prompted to enter their username and password. The system then validates the credentials and grants access based on the user type.

## Usage
1. To use the program, compile the C code using a C compiler (e.g., GCC).
2. Run the compiled executable to start the Student Management System.
3. The program will prompt you to log in as a student or a professor using the provided options.
4. Depending on the user type, you will have access to different functionalities.

## Notes
- The program does not implement advanced password security (e.g., hashing). Passwords are stored in plaintext in the files, which is not recommended for production use.
- Input validation and error handling are limited in the current implementation and could be improved to enhance robustness.

## Future Enhancements
The current implementation provides a basic framework for a student management system. Some possible future enhancements could include:

- Implementing password hashing and secure authentication methods.
- Adding more robust input validation to handle invalid user input.
- Enhancing error handling for file I/O operations and user interactions.
- Modularizing the code into separate functions for better readability and maintainability.
- Providing options to update student, course, and professor information.
- Adding features for course enrollment limits and prerequisites.

## Disclaimer
This code is provided as a sample implementation for educational purposes only. It may not be suitable for production use as-is and should be thoroughly reviewed, tested, and adapted to meet specific requirements before deployment.

## License
This code is provided under the [MIT License](LICENSE).

