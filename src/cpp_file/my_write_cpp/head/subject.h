#ifndef _SUBJECT_H__
#define _SUBJECT_H__
class Observer;
class Subject
{
public:
    virtual ~Subject() = 0 {};
    virtual void registerObserver(Observer*) = 0;
    virtual void removeOBserver(Observer *) = 0;
    virtual void notifyObserver(Observer *) = 0;


};

#endif