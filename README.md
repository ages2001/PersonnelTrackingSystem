# Personnel Tracking System with C++98

With the object-oriented programming method, it is desired to develop an application that will
enable the tracking of personnel (civil servants) working in a public institution. For this
purpose, it is desired to have quick access to the following data about the personnel through
both personnel numbers and dates of appointment to the institution:

Personnel number 4-digit integer
Name : string
Surname : string
Title : string
Salary coefficient : real number
Date of birth : Date (day, month and year separate integers)
Date of appointment to this institution : Date (day, month and year separate integers) 
Length of service in other institutions (days) : integer

To access staff information through the staff number, a circular single-linked list with a list-
head node ordered by staff number from smallest to largest will be used. To access staff
information through the date of appointment to the organization, a circular doubly-linked list
with a list-head node ordered by date of appointment to the organization will be used.

Accordingly, the requests listed below are requested to be realized through a menu:

**1) Appointment of a first-time civil servant to the organization**
<br>
First, the personnel number should be obtained from the user and if there is a personnel with
this number, no addition should be made, if not, the other information of the personnel should
be obtained from the user and the addition process should be performed.

**2) Appointment of a personnel transferred from another institution to the institution**
<br>
First, the personnel number should be obtained from the user and if there is a personnel with
this number, no addition should be made, if not, the other information of the personnel should
be obtained from the user and the addition process should be performed.

**3) Updating the title and salary coefficient of a staff member**
<br>
First, the staff number should be retrieved from the user and if there is a staff member with
this number, the title and salary coefficient should be updated.

**4) Deleting a staff member**
<br>
First, the staff number should be retrieved from the user and if there is a staff member with
this number, the deletion process should be performed.

**5) Listing the information of a staff member**
<br>
First, the staff number should be retrieved from the user and if there is a staff member with
this number, their information should be listed.

**6) Listing of all personnel in order of personnel number**
<br>
All staff information should be listed in ascending order by staff number.

**7) Listing of all personnel in order of date of appointment to the organization**
<br>
The information of all personnel should be listed in order from old to new according to the date
of appointment to the organization.

**8) Listing of personnel assigned to the organization after a certain date**
<br>
First, the date should be retrieved from the user and the information of all personnel appointed
to the organization after this date should be listed in reverse order according to the date of
appointment to the organization.

**9) Listing of personnel assigned to the organization in a given year**
<br>
First, the year should be taken from the user and the information of all personnel appointed to
the organization in this year should be listed in order from old to new according to the date of
appointment to the organization.

**10) Listing of personnel born before a certain date**
<br>
First, the date should be retrieved from the user and the information of all personnel born
before this date should be listed in ascending order by personnel number.

**11) Listing of personnel born in a specific month**
<br>
First, the month should be retrieved from the user and the information of all personnel born in
this month should be listed in ascending order by personnel number.

**12) Listing the information of the last personnel assigned to the organization from the
personnel with a specific title**
<br>
First, the title should be retrieved from the user and the information of the most recently
appointed personnel should be listed from the personnel with this title.

**NOTE-1:** Assume that data entries will be made correctly, no check for errors.
<br>
**NOTE-2:** To run the program, you just need to download the zip file from Releases and run the exe file in Console.
