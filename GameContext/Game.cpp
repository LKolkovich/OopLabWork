#include "Game.h"

Game::Game(PlayerController &controller, ReaderInterface *reader, Observer* observer) : controller_(controller), reader_(reader),
view_initializer_(nullptr), isRunning_(false), current_state_(nullptr), observer_(observer) {
    if(reader == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr in Game constructor");
    }

    if(observer == nullptr) {
        throw std::invalid_argument("observer can`t be nullptr in Game constructor");
    }

    observer_->registerSubject(reader);

    FileSettingsReader reader1;

    reader1.readOnStart("inp.txt");
    view_initializer_ = new SettingsViewInitializer(new DefaultInterpreter, new PickLogView);
    goToState(new PickLogState);
}

void Game::start() {
    if(reader_ == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr when game starts");
    }

    if(view_initializer_ == nullptr) {
        throw std::invalid_argument("view initializer can`t be nullptr when game starts");
    }

    if(current_state_ == nullptr) {
        throw std::invalid_argument("state can`t be nullptr when game starts");
    }

    observer_->registerSubject(&controller_);

    isRunning_ = true;
    view_initializer_->init();
    while (isRunning_) {
        Commands cmd = reader_->read();
        system("cls");
        observer_->check();
        current_state_->handle(cmd);
        view_initializer_->init();
    }
    observer_->check();
    system("cls");
//много состояний, каждый из которых решает, что будет происходить сейчас в игре. тут один метод, который вызывает обработчик внутри состояния
//если надо выйти в главное меню - меняется состояние, но не разрушается цикл
}

// сделать winState и loseState. при переходе к ним view заменяется на winView или loseView
// выводится "input *start button* for go to main menu" После ввода этого символа переход к MenuState


void Game::goToState(AbstractState *new_state) {
    if(new_state == nullptr) {
        throw std::invalid_argument("state can`t be nullptr when it`s given to Game");
    }
    delete current_state_;
    current_state_ = new_state;
    current_state_->setGameContext(this);
}

void Game::pickPremadeLevel(int number) {
    FieldBuilder fieldBuilder;
    controller_.set_field(&fieldBuilder.createPremadeLevel(number));
    prepareForRestart();
}

void Game::levelFromFile(const std::string &path) {
    FieldBuilder fieldBuilder;
    controller_.set_field(&fieldBuilder.createLevelFromFile(path));
    prepareForRestart();
}

void Game::prepareForRestart() {
    controller_.set_coordinates(controller_.field()->start());
    controller_.resetPlayer();
    controller_.makeStartMessage();
}

void Game::movePlayer(Sides direction) {
    controller_.move(direction);
}

void Game::quit() {
    isRunning_ = false;
}

bool Game::isLose() {
    return !controller_.doesAlive();
}

bool Game::isWin() {
    return controller_.field()->finish() == controller_.get_coordinates();
}

void Game::registerSubj(Observable* subj) {
    if(subj == nullptr) {
        throw std::invalid_argument("can`t register nullptr subject");
    }
    observer_->registerSubject(subj);
}

void Game::unregisterSubs(Observable* subj) {
    if(subj == nullptr) {
        throw std::invalid_argument("can`t unregister nullptr subject");
    }
    observer_->unregisterSubject(subj);
}

void Game::unregisterReader() {
    if(reader_ != nullptr) {
        unregisterSubs(reader_);
    }
}

void Game::setReader(ReaderInterface *reader) {
    if(reader == nullptr) {
        throw std::invalid_argument("reader can`t be nullptr when it`s given to Game");
    }
    delete reader_;
    reader_ = reader;
}

void Game::set_view_initializer(ViewInitializerInterface *view_init) {
    if(view_init == nullptr) {
        throw std::invalid_argument("view can`t be nullptr when it`s given to Game");
    }
    delete view_initializer_;
    view_initializer_ = view_init;
}

Game::~Game() {
    delete reader_;
    delete current_state_;
    delete view_initializer_;
    delete observer_;
}

Field& Game::field() {
    return *controller_.field();
}

Point Game::playerPosition() {
    return controller_.get_coordinates();
}

int Game::score() {
    return controller_.get_score();
}

int Game::health_points() {
    return controller_.get_health_points();
}

void Game::makeWinMessage() {
    controller_.makeWinMessage();
}

void Game::makeLoseMessage() {
    controller_.makeLoseMessage();
}

void Game::addStreamToObserver(StreamWrapperInterface *stream) {
    observer_->addStream(stream);
}