#include "School.h"
#include "Manager.h"
#include "Secretary.h"
//מימוש הבנאי
School::School()
{
	layer_school = new Layer*[6];
	qaun_layers = 6;
	all_persons = NULL;
	qaun_all_persons = 0;
	manager_exsit = false;
}

School::~School()
{
	if (all_persons)
		delete[]all_persons;
	delete[]layer_school;
}
//פונקציה ראשית המציגה את האפשרויות למשתמש
void School::Menu()
{
	//הכרזה על כל המשתנים הרלוונטים הנחוצים
	char _layer_name;
	int ID, _num_of_class, index = 0, quan_class_made = 0, seniority, children,max=0;
	string first_name, last_name; 
	Class c[18], *pointer;
	bool exsit = false,person_exsit=false,tutor_exs=false;
	//לולאת דו וויל המתקיימת עד לבחירת המשתמש לצאת החוצה
	int choice;
	do
	{
		cout << "Please enter your choice:\n";
		cout << " 1 - Add pupil\n";
		cout << " 2 - Add teacher\n";
		cout << " 3 - Add tutor\n";
		cout << " 4 - Add manager\n";
		cout << " 5 - Add secretary\n";
		cout << " 6 - Print workers and pupil details\n";
		cout << " 7 - Print outstanding people\n";
		cout << " 8 - Print tutor's class \n";
		cout << " 9 - Print worker details with biggest salary\n";
		cout << "10 - Exit\n";
		cin >> choice;
		switch (choice)
		{
			//הוספת תלמיד לתוך כיתה
		case 1:
			//בקשת פרטי התלמיד מהמשתמש
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Which layer?\t(a-f)";
			cin >> _layer_name;
			cout << "Which class in layer?\t(1-3)";
			cin >> _num_of_class;
			//במידה ואין אנשים במערך התלמיד נוסף למערך בתא הראשון
			//מתבצע עדכון לכמות האנשים שנוספו למערך
			//נוצרת כיתה בהתאם לדרישות התלמיד ולשם הוא מוכנס
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Pupil(first_name, last_name, ID, _num_of_class, _layer_name);
				Pupil *st = dynamic_cast<Pupil*>(all_persons[0]);
				if (st != NULL)
					st->add_grade();
				qaun_all_persons += 1;
				c[index].set_layer(_layer_name);
				c[index].set_class(_num_of_class);
				c[index].Add(st);
				quan_class_made += 1;
				index++;
			}
			//במידה וכבר קיימים אנשים במערך מתבצעת בדיקה האם התלמיד כבר קיים במערך
			//במידה והוא קיים הוא לא נוסף למערך
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true; 
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//במידה והתלמיד לא קיים במערך נוצר מערך חדש אליו אנחנו מעתיקים את המערך הישן ומכניסים בתא האחרון את התלמיד
				//המערך המקורי נמחק והוא מצביע למערך החדש שלנו
				//כמות האנשים במערך מתעדכנת
				//ישנה בדיקה לגבי פרטי הכיתה שהתלמיד הכניס
				//במידה והכיתה קיימת , לא נוצרת כיתה חדשה והוא פשוט מצורף לכיתה הקיימת
				//במידה ופרטי הכיתה שהוא הכניס לא קיימת עדיין , נוצרת כיתה כזו והוא מצורף לשם
				//מתבצע עדכון לכמות הכיתות שנוצרו.
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Pupil(first_name, last_name, ID, _num_of_class, _layer_name);
				Pupil *st = dynamic_cast<Pupil*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_grade();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						c[i].Add(st);
						exsit = true;
						break;
					}
				}
				if (!exsit)
				{
					c[index].set_layer(_layer_name);
					c[index].set_class(_num_of_class);
					c[index].Add(st);
					quan_class_made += 1;
					index++;
				}
			}
			break;
		case 2:	
			//הוספת מורה למערך בית הספר
			//בקשת פרטיו של המורה כולל שנות וותק
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//במידה ולא נוצרו אנשים במערך עדיין המורה נוסף לתא הרא שון במערך
			//מתבצע עדכון לכמות האנשים במערך
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Teacher(first_name, last_name, ID, seniority);
				Teacher *st = dynamic_cast<Teacher*>(all_persons[0]);
				if (st != NULL)
					st->add_profession();
				qaun_all_persons += 1;
			}
			//במידה וכבר ישנם אנשים במערך מתצבעת בדיקה על פי תעודת זהות האם המורה כבר קיים בבית הספר
			//במידה והוא קיים הוא לא נוסף למערך ומוצגת הודעה בהתאם
			//במידה והוא לא קיים נוצר מערך חדש אליו אנחנו מעתיקים את המערך הישן
			//בתא האחרון נוסף המורה החדש , המערך המקורי נמחק ומצביע על המערך החדש
			//כמות ה אנשים במערך מתעדכנת
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Teacher(first_name, last_name, ID, seniority);
				Teacher *st = dynamic_cast<Teacher*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_profession();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 3:
			//הוספת מחנך למערך בית הספר ושיוכו לכיתה
			//בקשת פרטי המחנך כולל באיזה שכבה ובאיזה כיתה הוא מלמד
			cout << "Hello, please enter your details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Which layer do you teach?\t(a-f)";
			cin >> _layer_name;
			cout << "Which class in layer do you teach?\t(1-3)";
			cin >> _num_of_class;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//במידה ולא קיימים אנשים במערך המחנך נוסף לתא הראשון
			//כמו כן נוצרת כיתה בהתאם לפרטים שהוא הכניס והוא משיוך לכיתה זו על ידי מצביע
			//מתעדכנת כמות האנשים במערך
			//מתעדכנת כמות הכיתות שיצרתי
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Tutor(first_name, last_name, ID, seniority);
				Tutor *st = dynamic_cast<Tutor*>(all_persons[0]);
				if (st != NULL)
					st->add_profession();
				qaun_all_persons += 1;
				c[index].set_layer(_layer_name);
				c[index].set_class(_num_of_class);
				c[index].Add_tutor(st);
				pointer = &c[index];
				st->Add_class(pointer);
				quan_class_made += 1;
				index++;
			}
			//במידה וכבר יש אנשים במערך מתבצעת בדיקה על פי תעודות זהות האם המחנך נמצא במערך
			//במידה וכן מוצגת הודעה מתאימה והוא לא נוסף למערך

			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//במידה והוא לא קיים במערך נוצר מערך חדש בגודל מתאים אליו מעתיקים את המערך הישן
				//בתא האחרון נוסך המחנך החדש
				//המערך הישן נמחק ומצביע על המערך החדש
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				//מתבצעת בדיקה האם פרטי הכיתה שהמחנך הכניס כבר קיימת במערכת
				//זאת אומרת האם נוצרה כיתה כזו ובמידה וכן
				//מתבצעת בדיקה לגבי הכיתה הספציפית האם כבר קיים מחנך לכיתה זו
				//מוצגת הודעה מתאימה אם יש מחנך לכיתה זו
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						if (c[i].tutor_exsit())
						{
							tutor_exs = true;
							cout << "There is a tutor to that class!\n";
							break;
						}
					}

				}
				//במידה וקיים מחנך לכיתה זו הוא לא נוסף למערך
				if (tutor_exs)
					break;
				//המחנך נוסף לתא האחרון
				help[qaun_all_persons] = new Tutor(first_name, last_name, ID, seniority);
				Tutor *st = dynamic_cast<Tutor*>(help[qaun_all_persons]);
				if (st != NULL)
					st->add_profession();
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
				//מתבצעת בדיקה האם פרטי הכיתה שהמחנך הכניס כבר קיימת במערכת
				//זאת אומרת האם נוצרה כיתה כזו
				//במידה וכן המחנך נוסף לכיתה והכיתה נוספת למחנך
				//זאת אומרת למחנך יש מצביע שיצביע על הכיתה הנל
				//ולכיתה יש מצביע שיצביע על המחנך שמחנך אותה
				for (int i = 0; i < quan_class_made; i++)
				{
					if (c[i].get_class() == _num_of_class && c[i].get_layer() == _layer_name)
					{
						c[i].Add_tutor(st);
						pointer = &c[i];
						st->Add_class(pointer);
						exsit = true;
						break;
					}
				}
				//במידה והכיתה לא קיימת עדיין נוצרת כיתה כזו על פרטים שהמחנך הכניס 
				//מתבצע עדכון לכמות הכיתות שנוצרו
				//המחנך נוסף לכיתה
				//הכיתה נוספת למחנך
				if (!exsit && !tutor_exs)
				{
					c[index].set_layer(_layer_name);
					c[index].set_class(_num_of_class);
					c[index].Add_tutor(st);
					pointer = &c[index];
					st->Add_class(pointer);
					quan_class_made += 1;
					index++;
				}
			}
			break;
		case 4:
			//הוספה של מנהל למערך בית הספר
			//בקשת פרטי המנהל כולל שנות וותק
			cout << "Hello, please enter Manager details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			//במידה והוא הר אשון במערך הוא נוסף לתא הראשון ומתבצע עדכון לכמות ה אנשים
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Manager(first_name, last_name, ID, seniority);
				qaun_all_persons += 1;
			}
			else
				//במידה וקיימים אנשים במערך מתבצעת בדיקה על פי תעודות זהות האם קיים תז במערך
				//במידה וכן מוצגת הודעה מתאימה והמנהל לא נוסף למערך
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//במידה והוא לא קיים במערך נוצר מערך חדש בגודל מתאים אליו מועתק המערך הישן
				//בתא האחרון נוסף המנהל
				//המערך הישן נמחק ומצביע על המערך החדש
				//מתבצע עדכון לכמות האנשים המערך
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Manager(first_name, last_name, ID, seniority);
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 5:
			//הוספת מזכירה למערך
			//בקשת פרטי המזכירה כולל שנות וותק וכמות ילדים בבית הספר
			cout << "Hello, please enter Secretary details:\n";
			cout << "First name: ";
			cin >> first_name;
			cout << "Last name: ";
			cin >> last_name;
			cout << "ID: ";
			cin >> ID;
			cout << "Years of Seniority: ";
			cin >> seniority;
			cout << "how many children in school?";
			cin >> children;
			//במידה ואין אנשים במערך המזכירה נוספת לתא הראשון ומתבצע עדכון לכמות האנשים
			if (!qaun_all_persons)
			{
				all_persons = new Person*[1];
				all_persons[0] = new Secretary(first_name, last_name, ID, seniority, children);
				qaun_all_persons += 1;
			}
			//במידה וקיימים אנשים במערך מתבצעת בדיקה על פי תעודת זהות לבדוק האם קיים תז זהה במערך
			//במידה וכן מוצגת הודעה מתאימה והמזכירה לא נוספת למערך
			else
			{
				for (int i = 0; i < qaun_all_persons; i++)
				{
					if (all_persons[i]->get_id() == ID)
					{
						cout << "Person already exsit\n";
						person_exsit = true;
						break;
					}
				}
				if (person_exsit)
				{
					person_exsit = false;
					break;
				}
				//במידה והמזכירה לא קיימת במערך נוצר מערך חדש בגודל מתאים אליו מועתק המערך הישן
				//בתא האחרון נוספת המזכירה
				//המערך הישן נמחק ומצביע על המערך החדש
				//מתבצע עדכון לכמות האנשים במערך
				Person **help = new Person*[qaun_all_persons + 1];
				for (int i = 0; i < qaun_all_persons; i++)
					help[i] = all_persons[i];
				help[qaun_all_persons] = new Secretary(first_name, last_name, ID, seniority, children);
				delete[]all_persons;
				all_persons = help;
				qaun_all_persons += 1;
			}
			break;
		case 6:
			//הדפסה של כל פרטי האנשים הנמצאים במערך בית הסםר
			//תלמידים, עובדים וכו
			for (int i = 0; i < qaun_all_persons; i++)
				all_persons[i]->print();
			break;
		case 7:
			//הדפסה של כל האנשים המצטיינים
			//מודפס כל המידע הרלוונטי לגבי האנשים המצטיינים
			cout << "Out Standing list:\n";
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (all_persons[i]->Outstanding())
					all_persons[i]->print();
			}
			break;
		case 8:
			//הדפסת פרטי כיתה לפי המחנך שלה
			//בקשת תעודת זהות של המחנך
			cout << "Hello , please enter Tutor id: ";
			cin >> ID;
			//בדיקה האם קיים במערך אדם עם תעודת זהות כזו
			//במידה וקיים מתבצעת בדיקה האם הוא מחנך
			//במידה והוא לא מחנך מוצגת הודעה מתאימה
			//במידה והוא אכן מחנך מודפס המידע לגבי הכיתה הנל כולל פרטי התלמידים הלומדים בכיתה
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (all_persons[i]->get_id() == ID)
				{
					Tutor *st = dynamic_cast<Tutor*>(all_persons[i]);
					if (st != NULL)
						st->print_class_info();
					else
						cout << "The ID is not belong to Tutor\n";
					break;
				}
			}
			break;
		case 9:
			//הדפסת פרטי האדם או האנשים שיש להם את המשכורת הכי גבוהה
			//לולאת פור הבודקת מהי המשכורת הכי גבוהה
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (max < all_persons[i]->paycheck())
					max = all_persons[i]->paycheck();
			}
			//לולאה הבודקת במערך למי יש את המשכורת הכי גבוהה והדפסת פרטיו
			//כמובן יכולים להיות שני אנשים במערך עם אותה משכורת (שהיא הכי גבוהה) והיא תדפיס את המידע של שניהם
			cout << "Worker details with the biggest salary is:\n\n";
			for (int i = 0; i < qaun_all_persons; i++)
			{
				if (max == all_persons[i]->paycheck() && max != 0)
					all_persons[i]->print();
			}
			break;
		case 10://יום נהדר
			system("cls");
			cout << "Have a Great Day :)\n";
			break;
		default: system("cls"); cout << "Try again\n";
		}
	} while (choice != 10);
}