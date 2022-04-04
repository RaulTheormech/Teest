#include <stdio.h>    
#include <string.h>
#include <math.h>
#include <fstream>
#include <time.h>

#include <iostream>
#include <stdlib.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace std;
void drawCircle(float); // Строим круг
void drawPlanets(); // Строим планеты (см. функции ниже)
void drawStars();

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //задает значения очистки цветом
} 
// RGB Red Green Blue

void handleKeypress(unsigned char key, int x, int y) { // Выход из программы при нажатии любой кнопки
	switch (key) { // switch это быстрый if при множестве вариантов (альтернатив)
	case 1:
		exit(0); // Выход из программы
		glClearColor(1.0f, 0.0f, 0.0f, 0.0f); // Очистка 
	}

}



// По умолчанию тест глубины отключен. Включим его.
void initRendering() { // Рендер
	glEnable(GL_DEPTH_TEST); // Запуск функции из gl. А именно: Тест глубины
}
// Теперь, с включенным тестом глубины OpenGL будет автоматически сохранять значения глубины
// для всех прошедших тест фрагментов и отбрасывать не прошедшие.


void handleResize(int w, int h) {
	glViewport(0, 0, w, h); // Функция задает окно просмотра.
	glMatrixMode(GL_PROJECTION); //Функция указывает, какая матрица является текущей матрицей.
	// Применяет последующие операции с матрицей к стеку матрицы проекции.

	glLoadIdentity(); //Функция заменяет текущую матрицу матрицей идентификаторов.
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0); // Функция настраивает матрицу перспективной проекции.
}

// Углы просмотра
// .f после числа делает его числом с плавающей запятой.
float mercury_angle = 30.0f;
float satrun_ring_angle = 30.0f;
float venus_angle = 30.0f;
float earth_angle = 30.0f;
float mars_angle = 30.0f;
float jupiter_angle = 30.0f;
float satrun_angle = 30.0f;
float uranus_angle = 30.0f;
float neptune_angle = 30.0f;
float _cameraAngle = 0.0f;

//Рисует 3д сцену
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищает указанные буферы, а именно
	// Очистка буфера цвета и 	Очистка буфера глубины.
	glMatrixMode(GL_MODELVIEW); // Применяет последующие матричные операции к стеку матриц представления модели.
	glLoadIdentity(); // заменяет текущую матрицу матрицей идентификаторов.
	glTranslatef(0.0f, 0.0, -50.0f); // модифицируем текущую матрицу ( которая в данный момент единичная).
	glScalef(0.4f, 0.4f, 0.4f); // меняет масштаб


	// Строим орбиты планет (данные взяты из интернета)
	drawCircle(4.62);
	drawCircle(9);
	drawCircle(12.5);
	drawCircle(18.8);
	drawCircle(30);
	drawCircle(39.5);
	drawCircle(52);
	drawCircle(63);

	// Строим звёзды
	drawStars();

	drawPlanets(); // Строим планеты
	glutSwapBuffers(); //После отрисовки мы переставляем (заменяем) буфера

	/*
	Swap Buffers - обмен буферов. Это очень полезно при анимации. 
	Мы используем окно с двойной буферизацией, один буфер отображаемый и второй - спрятанный. 
	В таком режиме инструкции OpenGL по рисованию изображений всегда применяются к спрятанному буферу. 
	Вызов функции glutSwapBuffers обменивает буфера, отображая окно целиком после того, как оно уже сформировано. 
	Эта технология обычна в компьютерной анимации, так как не позволяет человеческому глазу видеть, как линия за линией формируется кадр. 
	*/

}

void drawStars() {
	// Справа полностью
	glPushMatrix(); // Новая матрица со сдвигом вниз (начало)
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//Устанавливает опции для отрисовки многоугольника.
	/*
	Второй параметр указывает, как будет рисоваться многоугольник.
	Он принимает значения: GL_POINT(рисуются только точки), GL_LINE(рисуем линии) и GL_FILL(рисуем заполненный многоугольник).
	Первый параметр указывает: к лицевой, тыльной или же к обеим сторонам применяется опция, заданная вторым параметром.
	*/
	glColor3f(1, 1, 1); 	// Цвет RGB от 0 до 1
	glTranslatef(55, 0, 0.0f); // Смещение (X,Y,Z) (0.0.0) это центр (Солнце)
	glutSolidSphere(0.2, 50, 50); // Сфера с радиусом 0.2. 50 - ширина, 50 - долгота
	glEnd(); // Закончили рисовать
	glPopMatrix(); // Закончили с этой матрицей, идём дальше

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(48, 28, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 1, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(60, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(58, 30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd(); 
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(55, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, 35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(72, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, 20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(50, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(40, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(30, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(80, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, 25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	// Справа снизу

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(60, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(58, -30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(55, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, -35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(72, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, -20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(50, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(40, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(30, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(80, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(70, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(65, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(75, -25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();


	// Слева полностью
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 43, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 0, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-48, 28, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 1, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-60, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-58, 30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, 35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-72, 10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, 20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-50, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-40, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-30, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-80, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, 50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, 45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, 25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	// Справа снизу

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-60, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-58, -30, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-55, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, -35, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-72, -10, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, -20, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-50, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-40, -40, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-30, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-80, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-70, -50, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-65, -45, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(-75, -25, 0.0f);
	glutSolidSphere(0.2, 50, 50);
	glEnd();
	glPopMatrix();
}

void drawPlanets() {

	//Sun
	glPushMatrix(); //для сохранения и восстановления текущих координат
	/*
	Сдвигает текущий стек матриц на единицу вниз, дублируя текущую матрицу.
	То есть после вызова glPushMatrix матрица наверху стека идентична матрице под ним.
	*/
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //Она устанавливает опции для отрисовки многоугольника.
	/*
	Второй параметр указывает, как будет рисоваться многоугольник. 
	Он принимает значения: GL_POINT(рисуются только точки), GL_LINE(рисуем линии) и GL_FILL(рисуем заполненный многоугольник). 
	Первый параметр указывает: к лицевой, тыльной или же к обеим сторонам применяется опция, заданная вторым параметром.
	*/
	glColor3f(0.9, 0.9, 0.0);
	/*
	Следующие строки кода используют команду glColor3f(r, g, b). 
	Три ее параметра указывают насыщенность цвета красной, синей и зеленой составляющей. 
	Каждый из них может принимать значение от 0.0f до 1.0f.
	*/
	glutSolidSphere(2.5, 50, 50);
	// glutSolidSphere(GLdouble radius, GLint slices, GLint stacks)
	// Строит сферу с радиусом 2.5, 
	/*
	slices Количество делений вокруг оси Z. (широта)
	stacks Количество делений вдоль оси z. (долгота (см. глобус))
	*/
	glEnd(); // мы закончили рисовать приметив
	glPopMatrix(); // извлекает текущий стек матриц, заменяя текущую матрицу той, что находится под ней в стеке.

	// Дальше аналогично

	//Меркурий
	glPushMatrix();
	glRotatef(mercury_angle, 0.0f, 0.0f, 1.0f); // Поворот системы координат
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(1, 1, 1);
	glTranslatef(3.84f, 0.0, 0.0f); // Смещение системы координат для меркурия
	glutSolidSphere(0.492, 50, 50);
	glPopMatrix();

	//Венера
	glPushMatrix();
	glRotatef(venus_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(7.23f, 0.0, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(255.0, 215.0, 0.75);
	glutSolidSphere(0.4755, 50, 50);
	glPopMatrix();


	//Земля
	glPushMatrix();
	glRotatef(earth_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.137255, 0.137255, 0.556863);
	glTranslatef(10.0f, 0.0, 0.0f);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	//Марс
	glPushMatrix();
	glRotatef(mars_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.8, 0.0, 0.0);
	glTranslatef(15.2f, 0.0, 0.0f);
	glutSolidSphere(0.8, 50, 50);
	glPopMatrix();

	//Юпитер
	glPushMatrix();
	glRotatef(jupiter_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.36, 0.25, 0.20);
	glTranslatef(24.0f, 0.0f, 0.0f);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	//Сатурн
	glPushMatrix();
	glRotatef(satrun_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glTranslatef(32.0f, 0.0, 0.0f);
	glColor3f(0.2, 0.2, 0.2);
	glutSolidSphere(1.7, 50, 50);
	glPopMatrix();

	//Кольцо Сатурна
	glPushMatrix();
	glRotatef(satrun_ring_angle, 0.0f, 0.0f, 1.0f);
	glTranslatef(39.73f, 0.0, 0.0f);
	drawCircle(3);
	glPopMatrix();


	//Уран
	glPushMatrix();
	glRotatef(uranus_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5, 0.5, 1);
	glTranslatef(42.0f, 0.0, 0.0f);
	glutSolidSphere(1.6, 50, 50);
	glPopMatrix();

	//Нептун
	glPushMatrix();
	glRotatef(neptune_angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.35, 0.35, 0.67);
	glTranslatef(51.0f, 0.0, 0.0f);
	glutSolidSphere(1.5, 50, 50);
	glPopMatrix();
}


void drawCircle(float radius) { // Функция построения окружности с радиусом

	int cir_x = 0;
	int cir_y = 0;
	int min_angle = 0;
	int max_angle = 360;
	float theta;
	int i;
	float cir_x_itr;
	float cir_y_itr;
	float x;
	float y;

	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glBegin(GL_LINE_LOOP);
	for (i = min_angle; i <= max_angle; i++) {

		theta = 0.0174532925 * float(i); // 1 градус это 0.0174532925 радиан. Мы задаём i-ый итерационный угол
		cir_x_itr = radius * cosf(theta); // координаты для рисования i-ой итерационной точки по х и у
		cir_y_itr = radius * sinf(theta);

		x = cir_x + cir_x_itr;
		y = cir_y + cir_y_itr;

		glVertex3f(x, y, -30.0f); // Указывает вершины по координатам
	}
	glEnd();
	glPopMatrix();
}


void update_mercury(int value) {
	mercury_angle += 2.0f;
	if (mercury_angle > 360) {
		mercury_angle -= 360;
	}

	glutPostRedisplay(); // помечает активное окно, которое должно быть перерисовано, для вызова основного цикла
	glutTimerFunc(4.82, update_mercury, 0); 
	/*
	Эта функция устанавливает таймер. 
	Первый параметр millis задает время в миллисекундах, по истечении которых вызывается функция, 
	(вторая космическая скорость)
	которая указана как второй параметр. 
	Третий параметр value указывает индентификатор таймера, 
	т.е. таймеров может быть одновременно запущено несколько.
	*/
}

void update_venus(int value) {
	venus_angle += 2.0f;
	if (venus_angle > 360) {
		venus_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(10.3, update_venus, 0);
}


void update_earth(int value) {
	earth_angle += 2.0f;
	if (earth_angle > 360) {
		earth_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(15, update_earth, 0);
}

void update_mars(int value) {
	mars_angle += 2.0f;
	if (mars_angle > 360) {
		mars_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25.2, update_mars, 0);
}
void update_jupiter(int value) {
	jupiter_angle += 2.0f;
	if (jupiter_angle > 360) {
		jupiter_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(36.5, update_jupiter, 0);
}
void update_satrun(int value) {
	satrun_angle += 2.0f;
	if (satrun_angle > 360) {
		satrun_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40.2, update_satrun, 0);
}
void update_satrun_ring(int value) {
	satrun_ring_angle += 2.0f;
	if (satrun_ring_angle > 360) {
		satrun_ring_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(40.2, update_satrun_ring, 0);
}





void update_uranus(int value) {
	uranus_angle += 2.0f;
	if (uranus_angle > 360) {
		uranus_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(50.5, update_uranus, 0);
}
void update_neptune(int value) {
	neptune_angle += 2.0f;
	if (neptune_angle > 360) {
		neptune_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(61.8, update_neptune, 0);
}



int main(int argc, char** argv) {

	/*
	  glutInit(int **argcp, char **argv); 
	argc - это указатель на еще не измененную переменную argc главной функции программы (main). 
	После возврата из функции, значение, на которое указывает argcp, может измениться, 
	так как glutInit вычленяет все опции командной строки, относящиеся к библиотеке GLUT, 
	например, в системе X-Window все опции, относящиеся к управлению окнами, ассоциируются с GLUT. 
	argv - это еще не измененная переменная argv главной функции.  

	glutInit позаботится об инициализации переменных состояния GLUT 
	и откроет сессию с системой управления окнами.
	*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	/* Выбор режима окна:
   Одиночный буфер и RGBA палитра */
	glutInitWindowSize(1080, 720);
	/* Установка размеров окна */

	initGL(); // Очистка цвета

	glutCreateWindow("2D Solar System"); // Создание окна
	initRendering(); // Рендер с тестом глубины


	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);


	glutTimerFunc(4.82, update_mercury, 0);
	glutTimerFunc(12.3, update_venus, 0);
	glutTimerFunc(15, update_earth, 0);
	glutTimerFunc(25.2, update_mars, 0);
	glutTimerFunc(36.5, update_jupiter, 0);
	glutTimerFunc(40.2, update_satrun, 0);
	glutTimerFunc(40.2, update_satrun_ring, 0);
	glutTimerFunc(50.5, update_uranus, 0);
	glutTimerFunc(61.8, update_neptune, 0);

	glutMainLoop();
	return 0;
}



