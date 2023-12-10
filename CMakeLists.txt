cmake_minimum_required(VERSION 3.26)
project(code)

set(CMAKE_CXX_STANDARD 17)

add_executable(code main.cpp
        player/source/Player.cpp
        player/headers/Player.h
        player/headers/SIdes.h
        player/source/PlayerController.cpp
        player/headers/PlayerController.h
        field/source/Field.cpp
        field/headers/Field.h
        field/source/Cell.cpp
        field/headers/Cell.h
        field/headers/Point.h
        field/source/Point.cpp
        event/interface/EventInterface.h
        event/teleport/TeleportEvent.cpp
        event/teleport/TeleportEvent.h
        event/trap/TrapEvent.cpp
        event/trap/TrapEvent.h
        event/heal/HealEvent.cpp
        event/heal/HealEvent.h
        FieldBuilder/FieldBuilder.cpp
        FieldBuilder/FieldBuilder.h
        event/star/StarEvent.cpp
        event/star/StarEvent.h
        game/GameContext/Game.h
        game/GameContext/Game.cpp
        game/Reader/interface/AbstractReader.cpp
        game/Reader/CommandReader/StartReader.h
        game/Reader/CommandReader/StartReader.cpp
        game/View/GameView/AbstractView/AbstractGameView.cpp
        game/View/MenuView/AbstractMenuView.h
        game/Reader/GameReader/GameReader.cpp
        game/Commands/CommandsContainer.h
        game/Commands/CommandsContainer.cpp
        game/Interpretator/DefaultInterpreter.cpp
        game/Interpretator/DefaultInterpreter.h
        game/Interpretator/InterpreterInterface.h
        game/Interpretator/InterpreterInterface.cpp
        game/Reader/SettingsReader/ConsoleSettingsReader/DefaultConsoleSettingsReader/DefaultConsoleSettingsReader.h
        game/Reader/SettingsReader/ConsoleSettingsReader/DefaultConsoleSettingsReader/DefaultConsoleSettingsReader.cpp
        game/Reader/SettingsReader/ConsoleSettingsReader/IConsoleSettingsReader.h
        game/Reader/SettingsReader/FileSettingsReader/DefaultFileSettingsReader/DefaultFileSettingsReader.cpp)
