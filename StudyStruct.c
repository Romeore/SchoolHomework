//StudyStruct.c
#pragma once

#include "AlonDynamic.h"

struct studyHours
{
	char*          teacher;
	unsigned short subject;
	int            totalStudents;
};

//----------------------------------------------------------------------
//                           Schedule Long Teaching
//                           ---------------------- 
//
// General      : This function searches for a teacher that teaches
//                more than 4 hours in a row.
//
// Parameters   : 
//			schedulePtr - A pointer to schedule(mat). (studyHours)
//
// Return Value : Returns the address of a study hour that the teacher
//                teaches more than 4 hours in a row if it exists, 
//                else NULL.
//
//----------------------------------------------------------------------

struct studyHours* scheduleLongTeaching(struct studyHours** schedulePtr)
{
	struct studyHours* hoursPtr = *(schedulePtr);
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX - TWO;
	struct studyHours* sceduleLongTeaching = NULL;

	while (hoursPtr < schedulePtrEnd && sceduleLongTeaching == NULL)
	{
		hoursPtr -> teacher == (hoursPtr + ONE) -> teacher
			&& hoursPtr -> teacher == (hoursPtr + TWO) -> teacher ?
			(sceduleLongTeaching = hoursPtr) : (sceduleLongTeaching);
		(*schedulePtr - hoursPtr == FOUR) ? hoursPtr = *(++schedulePtr) : hoursPtr;
	}

	return (hoursPtr);
}

//----------------------------------------------------------------------
//                        Get How Much Hours Teacher Teach
//                        --------------------------------
//
// General      : This function calculates the number of hours that
//                a teacher teaches.
//
// Parameters   : 
//			schedulePtr - A pointer to schedule(mat). (studyHours)
//          teacherName - A name of teacher(char*)
//
// Return Value : Returns the amount of hours that a teacher teaches.
//
//----------------------------------------------------------------------

int getHowMuchHoursTeacherTeach(struct studyHours** schedulePtr, char* teacherName)
{
	struct studyHours* hoursPtr = *(schedulePtr);
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX;
	int                numOfHours;

	while (hoursPtr < schedulePtrEnd)
	{
		(hoursPtr -> teacher == teacherName) ? numOfHours += TWO : numOfHours;
		(*schedulePtr - hoursPtr == SIX) ? hoursPtr = *(++schedulePtr) : hoursPtr;
	}

	return (numOfHours);
}

//----------------------------------------------------------------------
//                     Get How Much Students Learn Subject
//                     -----------------------------------
//
// General      : This function calculates the number of students that
//                learn a specific subject.
//
// Parameters   : 
//			schedulePtr - A pointer to schedule(mat). (studyHours)
//          subjectPtr  - The number of the subject(unsigned short*)
//
// Return Value : Returns the amount of students that learn the subject.
//
//----------------------------------------------------------------------

int getHowMuchStudentsLearnSubject(struct studyHours** schedulePtr, unsigned short* subjectPtr)
{
	struct studyHours* hoursPtr = *(schedulePtr);
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX;
	int                numOfStudents;

	while (hoursPtr < schedulePtrEnd)
	{
		(hoursPtr)->subject == *(subjectPtr) ? numOfStudents += hoursPtr->totalStudents : numOfStudents;s
		(*schedulePtr - hoursPtr == SIX) ? hoursPtr = *(++schedulePtr) : hoursPtr;
	}

	return (numOfStudents);
}
