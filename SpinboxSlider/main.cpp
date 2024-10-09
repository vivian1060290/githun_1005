#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Enter Your Age");

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton *confirmButton = new QPushButton("確認");
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    spinBox->setMinimumWidth(100);
    QFont font = spinBox->font();
    font.setPointSize(8);
    spinBox->setFont(font);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);
    QObject::connect(confirmButton, &QPushButton::clicked, window, &QWidget::close);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addWidget(confirmButton);

    window->setLayout(mainLayout);

    window->show();
    return app.exec();
}
