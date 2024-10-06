#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFontDialog>

class MyApp : public QWidget {
    Q_OBJECT

public:
    MyApp(QWidget *parent = nullptr);

private slots:
    void changeFont();

private:
    QLabel *leaderLabel;
};

MyApp::MyApp(QWidget *parent) : QWidget(parent) {

    QTabWidget *tabs = new QTabWidget(this);

    QWidget *leaderTab = new QWidget();
    QWidget *member2Tab = new QWidget();

    tabs->addTab(leaderTab, "隊長");
    tabs->addTab(member2Tab, "組員2");

    leaderLabel = new QLabel("隊長\n組員2\n", leaderTab);
    leaderLabel->move(0, 0);


    QPushButton *fontButton = new QPushButton("改變文字樣式", member2Tab);
    fontButton->move(0, 0);
    connect(fontButton, &QPushButton::clicked, this, &MyApp::changeFont);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tabs);
    setLayout(layout);

    setWindowTitle("Qt Tabs Example");
    setGeometry(500, 500, 500, 500);
}

void MyApp::changeFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        leaderLabel->setFont(font);
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
