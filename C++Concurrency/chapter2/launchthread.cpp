class background_task
{
    public: void operator() () const
    {
        do_something();
        do_something_else();
    }
};

background_task f;
std::thread my_thread(f);

std::thread my_thread(background_task());

std::thread my_thread((background_task())); //1
std::thread my_thread{background_task()};   //2

std::thread my_thread( [] {
    do_something();
    do_something_else();
});

