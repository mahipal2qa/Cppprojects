#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Rock Paper Scissors");

    QLabel *resultLabel = new QLabel("Choose your weapon!", &window);
    QPushButton *rockButton = new QPushButton("Rock", &window);
    QPushButton *paperButton = new QPushButton("Paper", &window);
    QPushButton *scissorsButton = new QPushButton("Scissors", &window);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(resultLabel);
    layout->addWidget(rockButton);
    layout->addWidget(paperButton);
    layout->addWidget(scissorsButton);

    QObject::connect(rockButton, &QPushButton::clicked, [&]() {
        int computerChoice = rand() % 3;
        std::string computerMove;

        if (computerChoice == 0) {
            computerMove = "Rock";
        } else if (computerChoice == 1) {
            computerMove = "Paper";
        } else {
            computerMove = "Scissors";
        }

        if (computerMove == "Rock") {
            resultLabel->setText("Draw!");
        } else if (computerMove == "Paper") {
            resultLabel->setText("You Lose!");
        } else {
            resultLabel->setText("You Win!");
        }
    });

    // ... Similar connections for paperButton and scissorsButton

    window.show();
    return app.exec();
}