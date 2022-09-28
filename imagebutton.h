#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QPushButton>

class ImageButton : public QPushButton {
  QPixmap mCurrentButtonPixmap;
  QPixmap mButtonDownPixmap;
  QPixmap mButtonUpPixmap;

public:
  ImageButton() = default;

  explicit ImageButton(QWidget *parent);
  void paintEvent(QPaintEvent *e) override;

  [[nodiscard]] QSize sizeHint() const override;
  [[nodiscard]] QSize minimumSizeHint() const override;

  void keyPressEvent(QKeyEvent *e) override;
  void setDown();
  void setUp();
};
