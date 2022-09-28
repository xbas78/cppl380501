#include "imagebutton.h"

ImageButton::ImageButton(QWidget *parent) {
  setParent(parent);
  setToolTip("Stop");
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  mButtonUpPixmap = QPixmap("../red_button_up.png");
  mButtonDownPixmap = QPixmap("../red_button_down.png");
  mCurrentButtonPixmap = mButtonUpPixmap;
  setGeometry(mCurrentButtonPixmap.rect());
  connect(this, &QPushButton::clicked,
          this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e) {
  QPainter p(this);
  p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

[[nodiscard]] QSize ImageButton::sizeHint() const {
  return {100, 100};
}

[[nodiscard]] QSize ImageButton::minimumSizeHint() const {
  return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
  setDown();
}

void ImageButton::setDown() {
  mCurrentButtonPixmap = mButtonDownPixmap;
  update();
  QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp() {
  mCurrentButtonPixmap = mButtonUpPixmap;
  update();
}
