/*
  ============================================================================
  TOPIC: Math Game project
  AUTHOR: Eng. Abanoub Reda
  DESCRIPTION: a small math game project
  ============================================================================
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enums
enum enQuestionsLevel { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };
enum enOperationsType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

// Structure
struct stQuestion
{
	short FirstNumber = 0;
	short SecondNumber = 0;
	enOperationsType OperationType;
	enQuestionsLevel QestionLevel;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool IsCorrect = false;
};

struct stQuizz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions = 0;
	enQuestionsLevel QuestionLevel;
	enOperationsType OperationType;
	short CorrectAnswersCount = 0;
	short WrongAnswersCount = 0;
	bool IsPass = false;
};

// Helper Functions
int RandomNumber(int From, int To)
{
	int randomNumber = rand() % (To - From + 1) + From;
	return randomNumber;
}

enOperationsType GetRandomOperationType()
{
	int Operation = RandomNumber(1, 4);
	return (enOperationsType)Operation;
}

int SimpleCalculator(int FirstNumber, int SecondNumber, enOperationsType OperationType)
{
	switch (OperationType)
	{
	case enOperationsType::Add:
		return FirstNumber + SecondNumber;
		break;
	case enOperationsType::Sub:
		return FirstNumber - SecondNumber;
		break;
	case enOperationsType::Mul:
		return FirstNumber * SecondNumber;
		break;
	case enOperationsType::Div:
		return FirstNumber / SecondNumber;
		break;
	default:
		cout << "Please enter a correct operation\n";
	}
}

void ResetScreen()
{
	system("Color 0F");
	system("cls");
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("Color 2F");
	else
		system("Color 4F");
}

string GetOperationTypeSymbol(enOperationsType OperationType)
{
	string OperationTypes[] = { "+", "-", "*", "/", "Mix"};
	return OperationTypes[OperationType - 1];
}

string GetQuestionLevelWord(enQuestionsLevel QuestionLevel)
{
	string QuestionLevels[] = { "Easy", "Mid", "Hard", "Mix" };
	return QuestionLevels[QuestionLevel - 1];
}

string GetFinalResultText(bool isPass)
{
	if (isPass)
		return "Is Pass";
	else
		return "Is Fail";
}

void PrintQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\nQuestion [ " << QuestionNumber + 1 << " - " << Quizz.NumberOfQuestions << " ] \n\n";
	cout << Quizz.QuestionsList[QuestionNumber].FirstNumber << " ";
	cout << GetOperationTypeSymbol(Quizz.QuestionsList[QuestionNumber].OperationType) << " ";
	cout << Quizz.QuestionsList[QuestionNumber].SecondNumber << " = ";
}

void PrintFinalResult(stQuizz& Quizz)
{
	cout << "\n------------------------------------\n";
	cout << "Final Result is : ( " << GetFinalResultText(Quizz.IsPass) << " )";
	cout << "\n------------------------------------\n";
	cout << "Number of questions       : " << Quizz.NumberOfQuestions << endl;
	cout << "Question Level            : " << GetQuestionLevelWord(Quizz.QuestionLevel) << endl;
	cout << "Operation Type            : " << GetOperationTypeSymbol(Quizz.OperationType) << endl;
	cout << "Number of correct answers : " << Quizz.CorrectAnswersCount << endl;
	cout << "Number of wrong answers   : " << Quizz.WrongAnswersCount << endl;
	cout << "------------------------------------\n";
}

// System Logic
short ReadHowManyQuestions()
{
	short HowManyQuestions = 0;
	cout << "How many questions you want to answer                                 : ";
	cin >> HowManyQuestions;
	return HowManyQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel = 0;
	do
	{
		cout << "Enter questions level [1] Easy - [2] Mid - [3] Hard - [4] Mix         : ";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);
	return (enQuestionsLevel)QuestionsLevel;
}

enOperationsType ReadOperationsType()
{
	short OperationsType = 0;
	do
	{
		cout << "Enter operations type [1] Add - [2] Sub - [3] Mul - [4] Div - [5] Mix : ";
		cin >> OperationsType;
	} while (OperationsType < 1 || OperationsType > 5);
	return (enOperationsType)OperationsType;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevels, enOperationsType OperationsType)
{
	stQuestion Question;

	if (QuestionLevels == enQuestionsLevel::Mix)
		QuestionLevels = (enQuestionsLevel)RandomNumber(1, 3);
	if (OperationsType == enOperationsType::MixOp)
		OperationsType = GetRandomOperationType();

	Question.OperationType = OperationsType;
	switch (OperationsType)
	{
	case enQuestionsLevel::Easy:
		Question.FirstNumber = RandomNumber(1, 10);
		Question.SecondNumber = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		Question.QestionLevel = QuestionLevels;
		return Question;

	case enQuestionsLevel::Mid:
		Question.FirstNumber = RandomNumber(10, 50);
		Question.SecondNumber = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		Question.QestionLevel = QuestionLevels;
		return Question;

	case enQuestionsLevel::Hard:
		Question.FirstNumber = RandomNumber(50, 100);
		Question.SecondNumber = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.FirstNumber, Question.SecondNumber, Question.OperationType);
		Question.QestionLevel = QuestionLevels;
		return Question;
	}
	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OperationType);
	}
}

int ReadPlayerAnswer()
{
	int Number = 0;
	cin >> Number;
	return Number;
}

void CorrecrQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionsList[QuestionNumber].PlayerAnswer != Quizz.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionsList[QuestionNumber].IsCorrect = false;
		Quizz.WrongAnswersCount++;
		cout << "\nWorng answer :-( \nThe right answer is : " << Quizz.QuestionsList[QuestionNumber].CorrectAnswer << endl;
	}
	else
	{
		Quizz.QuestionsList[QuestionNumber].IsCorrect = true;
		Quizz.CorrectAnswersCount++;
		cout << "\nRight Answer :-)\n";
	}
	cout << endl;
	SetScreenColor(Quizz.QuestionsList[QuestionNumber].IsCorrect);
}

void AskAndCorrectQuestionIsAnswers(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		PrintQuestion(Quizz, Question);
		Quizz.QuestionsList[Question].PlayerAnswer = ReadPlayerAnswer();
		CorrecrQuestionAnswer(Quizz, Question);
	}
	Quizz.IsPass = (Quizz.CorrectAnswersCount >= Quizz.WrongAnswersCount);
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionsLevel();
	Quizz.OperationType = ReadOperationsType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionIsAnswers(Quizz);
	PrintFinalResult(Quizz);
}

void StartGame()
{
	char PlayAgin = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "\nDo you want to play agin ? [Y/N] : ";
		cin >> PlayAgin;
	} while (PlayAgin == 'Y' || PlayAgin == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
