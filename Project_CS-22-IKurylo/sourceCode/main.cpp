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

			cout << "1 - ����i�" << endl << "2 - �i� ��� ���������" << endl << "q - �����" << endl;
			cin >> tmp2;
			
			if(tmp2 == '2')
			{
            while (tmp != 'q')
            {
				cout << "1 - ��������� �������" << endl;
				cout << "2 - �i��i����� �������" << endl;
				cout << "3 - �������� �������" << endl;
				cout << "4 - ������ ���������" << endl;
				cout << "5 - ��������������" << endl;
				cout << "6 - �������� �� ������" << endl;
				cout << "q - ����� � ��������" << endl;

               cin >> tmp;

                if (tmp == 'q')
                    break;

                switch (tmp)
                {
                    case '1':
                        {
                            cout << endl;

							cout << "�i���i��� ����i� 1 ������i = ";
							cin >> n;
							cout << endl << "ʳ������ ������i� 1 ������i = ";
							cin >> m;

							k = n;
							l = m;

							a = obj2.Create(n, m);
							b = obj2.Create(k, l);

							cout << endl << "����i�� 1 �������" << endl;
							for (int i = 0; i < n; i++)
							{
								for (int j = 0; j < m; j++)
								{
									cout << "a[" << i << "][" << j << "] = ";
									cin >> a[i][j];
								}
								cout << endl;
							}

							cout << endl << "����i�� 2 �������" << endl;
							for (int i = 0; i < k; i++)
							{
								for (int j = 0; j < l; j++)
								{
									cout << "b[" << i << "][" << j << "] = ";
									cin >> b[i][j];
								}
								cout << endl;
							}

							cout << "���� :" << endl;
							obj.Plus(a, n, m, b, k, l);
							break;
					}
					case '2':
					{
						cout << "�i���i��� ����i� ������i = ";
						cin >> n;
						cout << "�i���i��� ������i� ������i = ";
						cin >> m;

						k = n;
						l = m;

						a = obj2.Create(n, m);
						b = obj2.Create(k, l);

						cout << endl << "����i�� 1 ������� " << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}

						cout << endl << "����i�� 2 �������" << endl;
						for (int i = 0; i < k; i++)
						{
							for (int j = 0; j < l; j++)
							{
								cout << "b[" << i << "][" << j << "] = ";
								cin >> b[i][j];
							}
							cout << endl;
						}

						cout << "�i����� :" << endl;
						obj.Minus(a, n, m, b, k, l);
						break;
					}
					case '3':
					{
						cout << "�i���i��� ����i� 1 ������i = ";
						cin >> n;
						cout << "�i���i��� ������i� 1 ������i = ";
						cin >> m;
						k = m;
						cout << "�i���i��� ������i� 2 ������i = ";
						cin >> l;

						a = obj2.Create(n, m);
						b = obj2.Create(k, l);

						cout << endl << "����i�� 1 �������" << endl;
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < m; j++)
							{
								cout << "a[" << i << "][" << j << "] = ";
								cin >> a[i][j];
							}
							cout << endl;
						}

						cout << endl << "����i�� 2 �������" << endl;
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
						cout << "�i���i��� ����i� i ������i� ������i = ";
						cin >> n;
						m = n;

						a = obj2.Create(n, m);

						cout << endl << "����i�� �������" << endl;
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

						cout << "�i���i��� ����i� ������i = ";
						cin >> n;
						cout << endl << "�i���i��� ������i� ������i = ";
						cin >> m;

						a = obj2.Create(n, m);
						b = obj2.Create(m, n);

						cout << endl << "����i�� �������" << endl;
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
						cout << "�i���i��� ����i� ������i = ";
						cin >> n;
						cout << endl << "�i���i��� ������i� ������i = ";
						cin >> m;

						a = obj2.Create(n, m);

						cout << endl << "����i�� �������" << endl;
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

						cout << "����i�� ����� ";
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
					cout << "1 - ��������� �������" << endl;
					cout << "2 - �i��i����� �������" << endl;
					cout << "3 - �������� �������" << endl;
					cout << "4 - ������ ���������" << endl;
					cout << "5 - ��������������" << endl;
					cout << "6 - �������� �� ������" << endl;
					cout << "q - ����� � ��������" << endl;

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
	


