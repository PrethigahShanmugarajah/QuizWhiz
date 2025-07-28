#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct
{
    char question[256];
    char options[4][256];
    int correctOption;
} Question;

void displayQuestion(Question q)
{
    printf("\nQuestion: %s\n", q.question);
    for (int i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int getAnswer()
{
    int answer;
    printf("\nEnter the number of your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

int main()
{

    Question quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Lisbon"}, 3},
        {"Which language is primarily used for web development?", {"C", "Java", "Python", "JavaScript"}, 4},
        {"What is the largest planet in our solar system?", {"Earth", "Mars", "Jupiter", "Saturn"}, 3},
        {"Who wrote 'Romeo and Juliet'?", {"Shakespeare", "Dickens", "Austen", "Hemingway"}, 1},
        {"What is the square root of 64?", {"6", "8", "10", "12"}, 2}};

    int score = 0;

    printf("Welcome to QuizWhiz! Test your knowledge.\n");

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        displayQuestion(quiz[i]);
        int answer = getAnswer();

        if (answer == quiz[i].correctOption)
        {
            printf("\nCorrect!\n");
            score++;
        }
        else
        {
            printf("\nWrong! The correct answer was option %d.\n", quiz[i].correctOption);
        }
    }

    printf("\nYou scored %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}
