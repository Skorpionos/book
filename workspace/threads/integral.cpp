#include "internal/io.h"

#include <iostream>
#include <cmath>
#include <pthread.h>

// функция создания потоков имеет следующую сигнатуру
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

// структура для хранения данных о задаче интегрирования
using Function = double (*)(double);

const int ThreadCount = 8;  // количество потоков

struct Task
{
    Function function; // функция
    double start;      // начальная точка отрезка
    double end;        // конечная точка отрезка
    double epsilon;    // шаг интегрирования
    double * result;   // куда записать результат
};

void* threadFunction(void* data)
{
    auto task = static_cast<Task*>(data);

    double result = 0;
    for (auto x = task->start; x < task->end; x += task->epsilon)
        result += task->function(x + task->epsilon / 2) * task->epsilon;

    *task->result = result;
    return nullptr;
}

// функция, которую будем интегрировать
double function(double x)
{
    return exp(x * sin(x));
}

int main()
{
    double results[ThreadCount] = {}; // массив, в который будут записаны результаты
    Task tasks[ThreadCount]     = {}; // задачи для потоков

    // пределы интегрирования
    double const start = -5;
    double const end   =  5;

    // заполняем задачи
    double const taskLength = (end - start) / ThreadCount;
    for (int index = 0; index < ThreadCount; ++index)
    {
        tasks[index].function = function;
        tasks[index].start    = start + taskLength * index;
        tasks[index].end      = tasks[index].start + taskLength;
        tasks[index].epsilon  = 1.0e-7;
        tasks[index].result   = &results[index];
    }

    pthread_t threads[ThreadCount]; // создаём дескрипторы потоков

    // создаём и запускаем потоки
    for (size_t index = 0; index != ThreadCount; ++index)
        pthread_create(&threads[index], nullptr, threadFunction, &tasks[index]);

    // дожидаемся завершения потоков
    for (size_t index = 0; index != ThreadCount; ++index)
        pthread_join(threads[index], nullptr);

    double result = 0;
    for (size_t index = 0; index != ThreadCount; ++index)
        result += results[index];

    std::cout << "Result: " << result << std::endl;

    return util::PrintComplete();
}