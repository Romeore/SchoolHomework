//StudyStruct.c
#pragma once

#include "AlonDynamic.h"

struct studyHours
{
	char*          teacher;
	unsigned short subject;
	int            totalStudents;
};

struct studyHours* scheduleLongTeaching(struct studyHours** schedulePtr)
{
	struct studyHours* hoursPtr = *(schedulePtr) + ONE;
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX - TWO;
	struct studyHours* sceduleLongTeaching = NULL;

	while (hoursPtr < schedulePtrEnd && sceduleLongTeaching == NULL)
	{
		hoursPtr -> teacher == (hoursPtr + ONE) -> teacher
			&& hoursPtr -> teacher == (hoursPtr + TWO) -> teacher ?
			(sceduleLongTeaching = hoursPtr) : (sceduleLongTeaching);
		(*schedulePtr - hoursPtr == FOUR) ? hoursPtr = *(++schedulePtr) + ONE : hoursPtr;
	}

	return (hoursPtr);
}

int getHowMuchHoursTeacherTeach(struct studyHours** schedulePtr, char* teacherName)
{
	struct studyHours* hoursPtr = *(schedulePtr)+ONE;
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX - TWO;
	int                numOfHours;

	while (hoursPtr < schedulePtrEnd)
	{
		(hoursPtr -> teacher == teacherName) ? numOfHours += TWO : numOfHours;
		(*schedulePtr - hoursPtr == FOUR) ? hoursPtr = *(++schedulePtr) + ONE : hoursPtr;
	}

	return (numOfHours);
}

int getHowMuchStudentsLearnSubject(struct studyHours** schedulePtr, unsigned short* subjectPtr)
{
	struct studyHours* hoursPtr = *(schedulePtr)+ONE;
	struct studyHours* schedulePtrEnd = schedulePtr + SIX * SIX - TWO;
	int                numOfStudents;

	while (hoursPtr < schedulePtrEnd)
	{
		(hoursPtr)->subject == *(subjectPtr) ? numOfStudents += hoursPtr->totalStudents : numOfStudents;s
		(*schedulePtr - hoursPtr == FOUR) ? hoursPtr = *(++schedulePtr) + ONE : hoursPtr;
	}

	return numOfStudents;
}

