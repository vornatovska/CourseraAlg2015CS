#include<iostream>
#include<math.h>
#include"matrix.h"
#include"Theory.h"
#include <locale.h>

using namespace std;

int main()
	{
		setlocale(LC_ALL, "Ukrainian");
			int n, m, k, l;

			Matrix obj;
			NewMatrix obj2;
			Theory obj3;

			double **a, **b; 

            char tmp = ' ';

			char tmp2 = ' ';

			cout << "1 - Теорiя" << endl << "2 - Дiї над матрицями" << endl << "q - Вийти" << endl;
			cin >> tmp2;
			
			if(tmp2 == '2')
			{
            while (tmp != 'q')
            {
				cout << "1 - Додавання матриць" << endl;
				cout << "2 - Вiднiмання матриць" << endl;
				cout << "3 - Множення матриць" << endl;
				cout << "4 - Знайти визначник" << endl;
				cout << "5 - Транспонування" << endl;
				cout << "6 - Множення на скаляр" << endl;
				cout << "q - Вийти з програми" << endl;

               cin >> tmp;

                if (tmp == 'q')
                    break;

                switch (tmp)
                {
                    case '1':
                        {
                            cout << endl;

							cout << "Кiлькiсть рядкiв 1 матрицi = ";
							cin >> n;
							cout << endl << "Кількість стовбцiв 1 матрицi = ";
							cin >> m;

							k = n;
							l = m;

							a = obj2.Create(n, m);
							b = obj2.Create(k, l);

							cout << endl << "Введiть 1 матрицю" << endl;
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
								{
									cout << "a[" << i << "][" << j << "] = ";
									cin >> a[i][j];
								}
								cout << endl;
							}

							cout << endl << "Введiть 2 матрицю" << endl;
							for (int i = 0; i < k; i++)
							{
								for (int j = 0; j < l; j++)
								{
									cout << "b[" << i << "][" << j << "] = ";
									cin >> b[i][j];
								}
								cout << endl;
							}

							cout << "Сума :" << endl;
							obj.Plus(a, n, m, b, k, l);
							break;
					}
					case '2':
					{
						cout << "Кiлькiсть рядкiв матрицi = ";
						cin >> n;
						cout << "Кiлькiсть стовбцiв матрицi = ";
						cin >> m;

						k = n;
						l = m;

						a = obj2.Create(n, m);
						b = obj2.Create(k, l);

						cout << endl << "Введiть 1 матрицю " << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}

						cout << endl << "Введiть 2 матрицю" << endl;
						for (int i = 0; i < k; i++)
						{
							for (int j = 0; j < l; j++)
							{
								cout << "b[" << i << "][" << j << "] = ";
								cin >> b[i][j];
							}
							cout << endl;
						}

						cout << "Рiзниця :" << endl;
						obj.Minus(a, n, m, b, k, l);
						break;
					}
					case '3':
					{
						cout << "Кiлькiсть рядкiв 1 матрицi = ";
						cin >> n;
						cout << "Кiлькiсть стовпцiв 1 матрицi = ";
						cin >> m;
						k = m;
						cout << "Кiлькiсть стовпцiв 2 матрицi = ";
						cin >> l;

						a = obj2.Create(n, m);
						b = obj2.Create(k, l);

						cout << endl << "Введiть 1 матрицю" << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}

						cout << endl << "Введiть 2 матрицю" << endl;
						for (int i = 0; i < k; i++)
						{
							for (int j = 0; j < l; j++)
							{
								cout << "b[" << i << "][" << j << "] = ";
								cin >> b[i][j];
							}
							cout << endl;
						}

						obj.Dobutok(a, n, m, b, k, l);
						break;
					}
					case '4':
					{
						cout << "Кiлькiсть рядкiв i стовпцiв матрицi = ";
						cin >> n;
						m = n;

						a = obj2.Create(n, m);

						cout << endl << "Введiть матрицю" << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}

						obj.Det(a, n, m);
						break;
					}
					case '5':
					{
						cout << endl;

						cout << "Кiлькiсть рядкiв матрицi = ";
						cin >> n;
						cout << endl << "Кiлькiсть стовпцiв матрицi = ";
						cin >> m;

						a = obj2.Create(n, m);
						b = obj2.Create(m, n);

						cout << endl << "Введiть матрицю" << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = "; 
								cin >> a[i][j];
							}
							cout << endl;
						}

						cout << endl;

						obj.Tran(a, b, n, m);
						break;
					}

					case '6':
					{
						double l;

						cout << endl;
						cout << "Кiлькiсть рядкiв матрицi = ";
						cin >> n;
						cout << endl << "Кiлькiсть стовпцiв матрицi = ";
						cin >> m;

						a = obj2.Create(n, m);

						cout << endl << "Введiть матрицю" << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}
						cout << endl;

						cout << "Введiть число ";
						cin >> l;

						obj.Skalar(a, n, m, l);
						break;
					}

					default:
						break;
				}
			}
			}

			if (tmp2 == '1')
			{

				while (tmp != 'q')
				{
					cout << "1 - Додавання матриць" << endl;
					cout << "2 - Вiднiмання матриць" << endl;
					cout << "3 - Множення матриць" << endl;
					cout << "4 - Знайти визначник" << endl;
					cout << "5 - Транспонування" << endl;
					cout << "6 - Множення на скаляр" << endl;
					cout << "q - Вийти з програми" << endl;

					cin >> tmp;

					if (tmp == 'q')
						break;

					switch (tmp)
					{
					case '1':
					{
						obj3.Plus();
						break;
					}
					case '2':
					{
						obj3.Minus();
						break;
					}
					case '3':
					{
						obj3.Dobutok();
						break;
					}
					case '4':
					{
						obj3.Det();
						break;
					}
					case '5':
					{
						obj3.Tran();
						break;
					}

					case '6':
					{
						obj3.Skalar();
						break;
					}

					default:
						break;

					}
				}
			}

			else
				return 0;
}
	


