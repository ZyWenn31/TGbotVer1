#include "Functions.h"




using namespace std;
using namespace TgBot;

vector<string>bot_commands = {"start"};


string MessageText = "Hello, everyone";

vector<string> GoMessegeToUsers()
{
    SQLite::Statement query(Data, "SELECT UserID FROM usstat");
    vector<string>UsersID;
    while (query.executeStep())
    {
        string Userid = query.getColumn(0);
        UsersID.push_back(Userid);
        Userid = "";
    }
    return UsersID;
}



bool HelloToUser(string n, string user, string ID)
{
    if (n == "User:")
    {
        SQLite::Statement insert(Data, "INSERT INTO usstat (Username, Status, UserID) VALUES (?, ?, ?)");
        insert.bind(1, user);
        insert.bind(2, "Member");
        insert.bind(3, ID);
        insert.exec();
        return true;
    }
    {
        return false;
    }
}

int main()
{
    TgBot::Bot bot("6595208040:AAHqjDoPmntRnsvaBF4zBb5-g4FiEZkMJdA");

    createtable();
    //Клавиатуры


    //out Клавиатура
    InlineKeyboardMarkup::Ptr outKey(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> Keout;
    InlineKeyboardButton::Ptr outBTN(new InlineKeyboardButton);
    outBTN->text = u8"На главную";
    outBTN->callbackData = u8"На главную";
    Keout.push_back(outBTN);
    outKey->inlineKeyboard.push_back(Keout);

    // to choose клавиатура
    InlineKeyboardMarkup::Ptr backKeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> backbtns;
    InlineKeyboardButton::Ptr backbtn(new InlineKeyboardButton);
    backbtn->text = u8"Перейти в выбор действий";
    backbtn->callbackData = u8"Выбор";
    backbtns.push_back(backbtn);
    backKeyboard->inlineKeyboard.push_back(backbtns);

    //YesNo Клавиатура
    InlineKeyboardMarkup::Ptr YesKey(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> Keyes;
    InlineKeyboardButton::Ptr GoBtn(new InlineKeyboardButton);
    GoBtn->text = "GO";
    GoBtn->callbackData = "GO";
    Keyes.push_back(GoBtn);
    Keout.push_back(outBTN);
    YesKey->inlineKeyboard.push_back(Keyes);
    YesKey->inlineKeyboard.push_back({ outBTN });

    // chooose delete funct клавиатура
    InlineKeyboardMarkup::Ptr OfFunctKeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> Offbtns;
    InlineKeyboardButton::Ptr OffTimeFunct(new InlineKeyboardButton), OffPasswordFunct(new InlineKeyboardButton), OffJokeFunct(new InlineKeyboardButton), OffQuestionFunct(new InlineKeyboardButton);
    OffTimeFunct->text = u8"Деактивировать 'время'";
    OffTimeFunct->callbackData = u8"ДеВремя";
    OffPasswordFunct->text = u8"Деактивировать 'Пароль'";
    OffPasswordFunct->callbackData = u8"ДеПароль";
    OffJokeFunct->text = u8"Деактивировать 'Шутка'";
    OffJokeFunct->callbackData = u8"ДеШутка";
    OffQuestionFunct->text = u8"Деактивировать 'Вопрос'";
    OffQuestionFunct->callbackData = u8"ДеВопрос";
    backbtns.push_back(backbtn);
    Offbtns.push_back(OffTimeFunct);
    Offbtns.push_back(OffPasswordFunct);
    Offbtns.push_back(OffJokeFunct);
    Offbtns.push_back(OffQuestionFunct);
    OfFunctKeyboard->inlineKeyboard.push_back({ OffTimeFunct });
    OfFunctKeyboard->inlineKeyboard.push_back({ OffPasswordFunct });
    OfFunctKeyboard->inlineKeyboard.push_back({ OffJokeFunct });
    OfFunctKeyboard->inlineKeyboard.push_back({ OffQuestionFunct });
    OfFunctKeyboard->inlineKeyboard.push_back({ backbtn });

    //joke Клавиатура
    InlineKeyboardMarkup::Ptr joKey(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> Kejok;
    InlineKeyboardButton::Ptr jkBtn(new InlineKeyboardButton);
    jkBtn->text = u8"Следующая шутка";
    jkBtn->callbackData = u8"Следующая шутка";
    Kejok.push_back(jkBtn);
    Keout.push_back(outBTN);
    joKey->inlineKeyboard.push_back({ jkBtn });
    joKey->inlineKeyboard.push_back({ outBTN });

    // AdminMenu Панель
    InlineKeyboardMarkup::Ptr AdminMenuKeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> AdminMenuBTNS;
    InlineKeyboardButton::Ptr UserFunct(new InlineKeyboardButton), MessageAllFunct(new InlineKeyboardButton), OffFunct(new InlineKeyboardButton);
    UserFunct->text = u8"Найти пользователя";
    UserFunct->callbackData = u8"Пользователь";
    MessageAllFunct->text = u8"Рассылка";
    MessageAllFunct->callbackData = u8"Рассылка";
    OffFunct->text = u8"Изменение функций";
    OffFunct->callbackData = u8"Изменение";
    AdminMenuBTNS.push_back(UserFunct);
    AdminMenuBTNS.push_back(MessageAllFunct);
    AdminMenuBTNS.push_back(OffFunct);
    Keout.push_back(outBTN);
    AdminMenuKeyboard->inlineKeyboard.push_back({ UserFunct });
    AdminMenuKeyboard->inlineKeyboard.push_back({ MessageAllFunct });
    AdminMenuKeyboard->inlineKeyboard.push_back({ OffFunct });
    AdminMenuKeyboard->inlineKeyboard.push_back({ outBTN });


    //Главная клавиатура 
    InlineKeyboardMarkup::Ptr Generalkeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> GeneralBTNS;
    InlineKeyboardButton::Ptr TimeFunct(new InlineKeyboardButton), PasswordFunct(new InlineKeyboardButton), JokeFunct(new InlineKeyboardButton), QuestionFunct(new InlineKeyboardButton);
    TimeFunct->text = u8"Узнать время";
    TimeFunct->callbackData = u8"Узнать время";
    PasswordFunct->text = u8"Получить пароль";
    PasswordFunct->callbackData = u8"Получить пароль";
    JokeFunct->text = u8"Получить шутку";
    JokeFunct->callbackData = u8"Получить шутку";
    QuestionFunct->text = u8"Получить ответ на вопрос";
    QuestionFunct->callbackData = u8"Получить ответ на вопрос";
    GeneralBTNS.push_back(TimeFunct);
    GeneralBTNS.push_back(PasswordFunct);
    GeneralBTNS.push_back(JokeFunct);
    GeneralBTNS.push_back(QuestionFunct);
    Generalkeyboard->inlineKeyboard.push_back({ TimeFunct });
    Generalkeyboard->inlineKeyboard.push_back({ PasswordFunct });
    Generalkeyboard->inlineKeyboard.push_back({ JokeFunct });
    Generalkeyboard->inlineKeyboard.push_back({ QuestionFunct });

    // Admin клавиатура
    InlineKeyboardMarkup::Ptr GeneralAdminkeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> GeneralAdminBTNS;
    InlineKeyboardButton::Ptr TimeFunct1(new InlineKeyboardButton), PasswordFunct1(new InlineKeyboardButton), JokeFunct1(new InlineKeyboardButton), QuestionFunct1(new InlineKeyboardButton), RRRRRRRR(new InlineKeyboardButton);
    TimeFunct1->text = u8"Узнать время";
    TimeFunct1->callbackData = u8"Узнать время";
    PasswordFunct1->text = u8"Получить пароль";
    PasswordFunct1->callbackData = u8"Получить пароль";
    JokeFunct1->text = u8"Получить шутку";
    JokeFunct1->callbackData = u8"Получить шутку";
    QuestionFunct1->text = u8"Получить ответ на вопрос";
    QuestionFunct1->callbackData = u8"Получить ответ на вопрос";
    RRRRRRRR->text = u8"Меню Администратора";
    RRRRRRRR->callbackData = u8"Меню";
    GeneralAdminBTNS.push_back(TimeFunct1);
    GeneralAdminBTNS.push_back(PasswordFunct1);
    GeneralAdminBTNS.push_back(JokeFunct1);
    GeneralAdminBTNS.push_back(QuestionFunct1);
    GeneralAdminBTNS.push_back(RRRRRRRR);
    GeneralAdminkeyboard->inlineKeyboard.push_back({ TimeFunct1 });
    GeneralAdminkeyboard->inlineKeyboard.push_back({ PasswordFunct1 });
    GeneralAdminkeyboard->inlineKeyboard.push_back({ JokeFunct1 });
    GeneralAdminkeyboard->inlineKeyboard.push_back({ QuestionFunct1 });
    GeneralAdminkeyboard->inlineKeyboard.push_back({ RRRRRRRR });

    // клавиатура изменений кнопок ButtonStatusUpdate
    InlineKeyboardMarkup::Ptr ResetBtnsKeyboard(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> ResetBTNS;
    InlineKeyboardButton::Ptr PlusBtn(new InlineKeyboardButton), MinusBtn(new InlineKeyboardButton);
    PlusBtn->text = u8"Активация кнопок";
    PlusBtn->callbackData = u8"Активация";
    MinusBtn->text = u8"Деактивация кнопок";
    MinusBtn->callbackData = u8"Деактивация";
    ResetBTNS.push_back(PlusBtn);
    ResetBTNS.push_back(MinusBtn);
    Keout.push_back(outBTN);
    ResetBtnsKeyboard->inlineKeyboard.push_back({ PlusBtn });
    ResetBtnsKeyboard->inlineKeyboard.push_back({ MinusBtn });
    ResetBtnsKeyboard->inlineKeyboard.push_back({ outBTN });


    //password клавиатура
    InlineKeyboardMarkup::Ptr keyboardToPassword(new InlineKeyboardMarkup);
    vector<InlineKeyboardButton::Ptr> PassBtn;
    InlineKeyboardButton::Ptr eightBtn(new InlineKeyboardButton), nineBtn(new InlineKeyboardButton), tenBtn(new InlineKeyboardButton), elevBtn(new InlineKeyboardButton), twelvBtn(new InlineKeyboardButton), moreBtn(new InlineKeyboardButton);
    eightBtn->text = "8";
    nineBtn->text = "9";
    tenBtn->text = "10";
    elevBtn->text = "11";
    twelvBtn->text = "12";
    moreBtn->text = "more";
    eightBtn->callbackData = "8";
    nineBtn->callbackData = "9";
    tenBtn->callbackData = "10";
    elevBtn->callbackData = "11";
    twelvBtn->callbackData = "12";
    moreBtn->callbackData = "more";
    PassBtn.push_back(eightBtn);
    PassBtn.push_back(nineBtn);
    PassBtn.push_back(tenBtn);
    PassBtn.push_back(elevBtn);
    PassBtn.push_back(twelvBtn);
    PassBtn.push_back(moreBtn);
    Keout.push_back(outBTN);
    keyboardToPassword->inlineKeyboard.push_back(PassBtn);
    keyboardToPassword->inlineKeyboard.push_back({ outBTN });
    //Конец клавиатур




    bot.getEvents().onCommand("start", [&bot, &Generalkeyboard, &outKey, &GeneralAdminkeyboard, &AdminMenuKeyboard](TgBot::Message::Ptr message)
        {

            bot.getApi().sendMessage(message->chat->id, u8"Привет, \t" + message->chat->firstName);
            if (HelloToUser(SearchUser(message->chat->username), message->chat->username, to_string(message->chat->id))) {
                bot.getApi().sendMessage(message->chat->id, u8"Вы успешно зарегестрированы");
                cout << "New registed user: " << message->chat->username << " ID: " << message->chat->id << " Time: " << get_time_as_str() << endl;
            }
            else {
                bot.getApi().sendMessage(message->chat->id, u8"Вы успешно авторизованы");
                cout << "autarization user: " << message->chat->username << " ID: " << message->chat->id << " Time: " << get_time_as_str() << endl;
            }
            if (AdminOrNo(message->chat->username)) {
                bot.getApi().sendMessage(message->chat->id, u8"Добро пожаловать в бота <название бота>, бот умеет:\n - Показывать время\n - генерировать шутки на различные темы\n - давать односложный ответ на вопрос\n - генерировать пароли различной длинны\n Бот предназначен для ежедневного использования, по всем вопросам писать в поддержку : @Пример.\n Приятного использования!", false, 0, GeneralAdminkeyboard);
            }
            else {
                bot.getApi().sendMessage(message->chat->id, u8"Добро пожаловать в бота <название бота>, бот умеет:\n - Показывать время\n - генерировать шутки на различные темы\n - давать односложный ответ на вопрос\n - генерировать пароли различной длинны\n Бот предназначен для ежедневного использования, по всем вопросам писать в поддержку : @Пример.\n Приятного использования!", false, 0, Generalkeyboard);
            }

        });

    bot.getEvents().onCallbackQuery([&bot, &Generalkeyboard, &outKey, &YesKey, &keyboardToPassword, &GeneralAdminkeyboard, &AdminMenuKeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"На главную")
            {
                if (AdminOrNo(query->message->chat->username)) {
                    bot.getApi().sendMessage(query->message->chat->id, u8"Добро пожаловать в бота <название бота>, бот умеет:\n - Показывать время\n - генерировать шутки на различные темы\n - давать односложный ответ на вопрос\n - генерировать пароли различной длинны\n Бот предназначен для ежедневного использования, по всем вопросам писать в поддержку : @Пример.\n Приятного использования!", false, 0, GeneralAdminkeyboard);
                }
                else {
                    bot.getApi().sendMessage(query->message->chat->id, u8"Добро пожаловать в бота <название бота>, бот умеет:\n - Показывать время\n - генерировать шутки на различные темы\n - давать односложный ответ на вопрос\n - генерировать пароли различной длинны\n Бот предназначен для ежедневного использования, по всем вопросам писать в поддержку : @Пример.\n Приятного использования!", false, 0, Generalkeyboard);
                }

            }
        });

    bot.getEvents().onCallbackQuery([&bot, &Generalkeyboard, &outKey, &GeneralAdminkeyboard, &AdminMenuKeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Меню")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Добро пожаловать в панель управления ботом для админов, с её помощью можно управлять: 1 2 3.", false, 0, AdminMenuKeyboard);

            }
        });




    bot.getEvents().onCallbackQuery([&bot, &AdminMenuKeyboard, &outKey, &ResetBtnsKeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Изменение")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"На данный момент: ");
                if (StatusTime())
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🟢 Функция 'время' доступна и кнопка активна.");
                }
                else
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🔴 Функция 'время' не доступна и кнопка не активна.");
                }

                if (StatusPassword())
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🟢 Функция 'Пароль' доступна и кнопка активна.");
                }
                else
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🔴 Функция 'Пароль' не доступна и кнопка не активна.");
                }

                if (StatusJoke())
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🟢 Функция 'Генерация шутки' доступна и кнопка активна.");
                }
                else
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🔴 Функция 'Генеррация шутки' не доступна и кнопка не активна.");
                }

                if (StatusAnswer)
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🟢 Функция 'Ответ на вопрос' доступна и кнопка активна.");
                }
                else
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"🔴 Функция 'Ответ на вопрос' не доступна и кнопка не активна.");
                }
                bot.getApi().sendMessage(query->message->chat->id, u8"Выберите, что необходимо сделать с кнопками? ", false, 0, ResetBtnsKeyboard);
            }
        });

    bot.getEvents().onCallbackQuery([&bot, &AdminMenuKeyboard, &outKey, &ResetBtnsKeyboard, &OfFunctKeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Деактивация")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Какие кнопки необходимо отключить?", false, 0, OfFunctKeyboard);
            }
        });

    // доделать деактивацию и активацию кнопок (с проверкой)
    bot.getEvents().onCallbackQuery([&bot, &AdminMenuKeyboard, &outKey, &ResetBtnsKeyboard, &OfFunctKeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Деактивация")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Какие кнопки необходимо отключить?", false, 0, OfFunctKeyboard);
            }
        });



    bot.getEvents().onCallbackQuery([&bot, &keyboardToPassword, &Generalkeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Получить пароль")
            {

                bot.getApi().sendMessage(query->message->chat->id, u8"Сколько символов должен содержать пароль?\t", false, 0, keyboardToPassword);
                cout << "(Password) function was used be the user: " << query->message->chat->username << endl;
            }
        });

    bot.getEvents().onCallbackQuery([&bot, &keyboardToPassword, &outKey](CallbackQuery::Ptr query)
        {
            if (query->data == "8")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Твой сгенерированный пароль:"); // Сделать отправление сообщения как тут
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(8), false, 0, outKey);
            }
            else if (query->data == "9")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Your generated password:");
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(9), false, 0, outKey);
            }
            else if (query->data == "10")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Your generated password:");
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(10), false, 0, outKey);
            }
            else if (query->data == "11")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Your generated password:");
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(11), false, 0, outKey);
            }
            else if (query->data == "12")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Your generated password:");
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(12), false, 0, outKey);
            }
            else if (query->data == "more")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Your generated password:");
                bot.getApi().sendMessage(query->message->chat->id, generateRandomParol(20), false, 0, outKey);
            }
        });






    bot.getEvents().onCallbackQuery([&bot, &Generalkeyboard, &outKey](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Узнать время")
            {
                if (StatusTime())
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"Moscow time is:\n" + get_time_as_str(), false, 0, outKey);
                    cout << "(Time) function was used be the user: " << query->message->chat->username << endl;
                }
                else
                {
                    bot.getApi().sendMessage(query->message->chat->id, u8"Поростите, данная функция недоступна для работы в данное время :(", false, 0, outKey);
                }
            }
        });


    bot.getEvents().onCallbackQuery([&bot, &Generalkeyboard, &joKey, &outKey](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Получить шутку")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"При нажатии на кнопку (Следующая шутка), вы увидете шутку на случайную тему.\t", false, 0, joKey);
                cout << "(joke) function was used be the user: " << query->message->chat->username << endl;
            }
        });

    bot.getEvents().onCallbackQuery([&bot, &joKey, &outKey](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Следующая шутка")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Сгенерированная шутка:\n" + Punchline(), false, 0, joKey);
            }
        });



    bot.getEvents().onCallbackQuery([&bot, &YesKey, &outKey, &Generalkeyboard](CallbackQuery::Ptr query)
        {
            if (query->data == u8"Получить ответ на вопрос")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"При нажатии на кнопку вы сможете ввести вопрос, подрузумивающий однозначный ответ (Да/Нет), и с малой вероятностью (может быть), будьте внимательны, кнопку следует нажимать только единожды, при последующем нажатии работа будет неверной.\t", false, 0, YesKey);
                cout << "(question) function was used be the user: " << query->message->chat->username << endl;
            }
        });

    bot.getEvents().onCallbackQuery([&bot, &outKey, &YesKey](CallbackQuery::Ptr query)
        {
            if (query->data == "GO")
            {
                bot.getApi().sendMessage(query->message->chat->id, u8"Введите вопрос, обязательно используйте знак (?) в конце:");
                bot.getEvents().onAnyMessage([&bot, &outKey](Message::Ptr message)
                    {
                        if (TakeQuestion(message->text))
                        {
                            bot.getApi().sendMessage(message->chat->id, u8"Полученный ответ:\t" + YesNoMaybe(), false, 0, outKey);
                            cout << "user " << message->chat->username << " Get answer" << endl;
                        }
                    });


            }
        });


    bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message)
        {
            for (const auto& command : bot_commands)
            {
                if ("/" + command == message->text || TakeQuestion(message->text))
                {
                    return;
                }
            }
            bot.getApi().sendMessage(message->chat->id, u8"Неизвестная команда");
        });

    try
    {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        TgBot::TgLongPoll longPoll(bot);
        while (true)
        {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgBot::TgException& e) {
        printf("error: %s\n", e.what());
        cout << endl << get_time_as_str() << endl;
        return 0;
    }
}