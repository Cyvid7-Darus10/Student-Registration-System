# Student Registration System
![N|Solid](https://cdn.iconscout.com/icon/free/png-512/c-programming-569564.png)

This project is about a simple registration system for students which are enrolled in the subject CMSC 11

# Summary
  - It has Password Encryption in order for the some functions to be only limited to some user
- It has two modes which are the admin and the student. In the admin you can basically do everything while on student mode the user can only view subjects, enroll in them, drop them and update their record.
- You can also import a list of students and subjects but when importing a student with an unknown subject enrolled in the program asks the user if he wants to create that subject or import from masterlist or exit where the unknown subject will just be saved as none
- The user if on admin mode has also a delete all function and the admin can also update subject records and all of the student records 
- The admin user name is "admin" and the password is "admin" as for the student, his/her username is her Student ID and her password is his/her lastname
- The project is made out entirely of c language and uses only the stdio.h header in the back end part while the other headers are for the user-friendly GUI
- The Project uses structs and pointers as well as different functions made by the programmers
- Download all the files and enjoy!

# Full Details

This is a CMSC11-Student Registration System program created by a group of students from University of the Philippines Cebu.
    
>And by default, CMSC11 is the default subject of this program.
>This program auto saves files you have created and to extract these files you need >to copy the default [data.csv and subjectlist.csv] file and rename it.

### This program features:
#
##### Log On Credentials 
#
>if admin [username: admin | password: admin], else if registered student [username: (studentID) | password: (studentLastName)]

##### Note:
#
>for every invalid credentials the program will be terminated
#
# For Admin
- Diplay All (Students or Subjects) Records 
    >display all student records with the highest, lowest, average, and standard deviaion of scores
    	
	• HD (High Distinction) = total score of 135 poins or more 
	• D (Distinction) = total score of 120 to 134 points 
	• P (Pass) = total score of 100 to 119 points
	• C (Credit) = total score of 75 to 99 points
	• F (Fail) = total score of 74 points and below 
- Import (Students or Subjects) File 
    > You can import (.csv) or (.txt) file by inputting filename or the location path of file

- (Student or Subject) Files should be on this format: 

    	For Student {
    	studentID,lastName,firstName,section,score1,score2,score3,subject1,subject2,subject3
    	189,Valde,Carl Michael,A1,50,50,50,CMSC11,CMSC21,MATH53
    	191,Pastelero,Cyrus David,A1,50,50,50,CMSC11,none,none
    	192,Sanico,Joshua,A1,50,50,50,none,none,none
    	}
    #    	
    	For Subject {
    	sujectID,subjectCode,subjectTitle
    	11,CMSC11,Introduction to Computer Science
    	}
    	
- Registration of (Student or Subject)

    - Register New Student
    - Enroll Student via Student ID and Subject Code
    - Drop Student via Student ID and Subject Code
    - Update Student via Student ID manually with choices what to update
    - Delete Student Record via Student ID
    - Register New Subject
    - Update Subject via Subject ID manually with choices what to update
    - Delete Student Record via Subject Code
	- Search (Student/s or Subject/s) Record/s
	> 
            Search Student/s Record/s via Student Lastname
		    Search Subject/s Record/s via Subject Code
	- Delete All Records
	>      
            Delete all records leaving default (CMSC11) subject 

- For Registered Student 
	- Drop Subject via Subject Code
	- Enroll Subject via Subject Code
	- Update Own Records
	- Display Subjects
	- Search Subject Records via Subject Code

### Limitation of the Program:
- All registered students are given a maximum of 3 subject slots with a default (CMSC11) subject
- All new registered students is eventually enrolled to default (CMSC11) subject
- All registered students are unable to drop the default (CMSC11) subject
- Unable to register new student with the same student ID of already registered student
 - Unable to register new subject with the same subject ID or subject code of already registered subject
- All registered students are given a maximum of 3 scores with a 100% score of 50 points
- If a student is unenrrolled to default (CMSC11) subject, the program will ask to enroll the student, otherwise, the student will be unregistered
- A maximum of 100 students will be registered
- A maximum of 100 subjects will be registered
- If the subject is unregistered, the program will ask to create that subject with exactly the same subject code, otherwise, a student will be unenrolled to that specific subject

### NOTE:
• Copy all the files from the CMSC11-Student Registration Syztem.zip folder
• Use Codeblocks and set console to fullscreen mode to have an undistorted User Interface
• Default Subject can be updated with the New Subject Code or New Subject Title
• I have provided you (student.txt and subject.txt) file samples to test
• Import first the subject file to get rid of creating unregistered subject
• And by default the file is empty with only default (CMSC11) subject registered

Thank you.
