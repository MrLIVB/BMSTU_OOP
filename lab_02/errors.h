
#ifndef ERRORS_H
#define ERRORS_H

#include <stdio.h>
#include <string.h>
#include <exception>

class BaseException : public std::exception
{
protected:
    char *errormsg;

public:
    BaseException(const char *msg, const char *file, const int line, const char *time)
    {
        int len = strlen(msg) + strlen(file) + 4 + strlen(time) + 40;
        this->errormsg = new char[len];
        sprintf_s(errormsg, len, "%s\nIn file %s:%d \nTime: %s", msg, file, line, time);
    }
    virtual ~BaseException() { delete[] errormsg; }

    virtual const char *what() const noexcept override { return this->errormsg; }
};

class IndexError : public BaseException
{
private:
    const char *errIndexMsg = "Incorrect index";
    int ind;

public:
    IndexError(const char *msg, const char *file, const int line, const char *time, int index)
        : BaseException(msg, file, line, time), ind(index) {}
    virtual ~IndexError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s: %4d", errormsg, errIndexMsg, ind);

        char *temp = errormsg;
        delete[] temp;

        const_cast<IndexError *>(this)->errormsg = buff;

        return errormsg;
    }
};

// Ошибка аллокации
class AllocationError : public BaseException
{
private:
    const char *errIndexMsg = "Error in allocation of size: ";
    int ind;

public:
    AllocationError(const char *msg, const char *file, const int line, const char *time, int index)
        : BaseException(msg, file, line, time), ind(index) {}
    virtual ~AllocationError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s%d", errormsg, errIndexMsg, ind);

        char *temp = errormsg;
        delete[] temp;

        const_cast<AllocationError *>(this)->errormsg = buff;

        return errormsg;
    }
};

// Пустой вектор
class EmptyVectorError : public BaseException
{
private:
    const char *errIndexMsg = "Vector is empty!";
    int ind;

public:
    EmptyVectorError(const char *msg, const char *file, const int line, const char *time)
        : BaseException(msg, file, line, time) {}
    virtual ~EmptyVectorError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s", errormsg, errIndexMsg);

        char *temp = errormsg;
        delete[] temp;

        const_cast<EmptyVectorError *>(this)->errormsg = buff;

        return errormsg;
    }
};

// деление на ноль
class ZeroDivisionError : public BaseException
{
private:
    const char *errIndexMsg = "Zero division";
    int ind;

public:
    ZeroDivisionError(const char *msg, const char *file, const int line, const char *time)
        : BaseException(msg, file, line, time) {}
    virtual ~ZeroDivisionError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s", errormsg, errIndexMsg);

        char *temp = errormsg;
        delete[] temp;

        const_cast<ZeroDivisionError *>(this)->errormsg = buff;

        return errormsg;
    }
};

// Нулевая длина
class ZeroLengthError : public BaseException
{
private:
    const char *errIndexMsg = "Zero division";
    int ind;

public:
    ZeroLengthError(const char *msg, const char *file, const int line, const char *time)
        : BaseException(msg, file, line, time) {}
    virtual ~ZeroLengthError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s", errormsg, errIndexMsg);

        char *temp = errormsg;
        delete[] temp;

        const_cast<ZeroLengthError *>(this)->errormsg = buff;

        return errormsg;
    }
};

// Отсутствующий указатель
class ExpiredPointerError : public BaseException
{
private:
    const char *errIndexMsg = "Pointer has expired";
    int ind;

public:
    ExpiredPointerError(const char *msg, const char *file, const int line, const char *time)
        : BaseException(msg, file, line, time) {}
    virtual ~ExpiredPointerError() {}

    virtual const char *what() const noexcept override
    {
        int Len = strlen(errormsg) + strlen(errIndexMsg) + 8;

        char *buff = new char[Len + 1];

        sprintf_s(buff, Len, "%s%s", errormsg, errIndexMsg);

        char *temp = errormsg;
        delete[] temp;

        const_cast<ExpiredPointerError *>(this)->errormsg = buff;

        return errormsg;
    }
};

#endif // !ERRORS_H