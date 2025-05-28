#include <iostream>
#include "Date.h"

using namespace std;
using namespace Date;

int main() {
    // Bugünün tarihi
    stDate today = GetTodayDate();
    PrintDate("Today's Date:", today);

    // 10 gün ekleyerek yeni tarihi bulma
    stDate future = IncreaseDateByXDays(today, 10);
    PrintDate("After 10 Days:", future);

    // 3 ay önceki tarihi bulma
    stDate past = DecreaseDateByXMonths(today, 3);
    PrintDate("3 Months Ago:", past);

    // Belirli bir yılı takvim olarak yazdır
    PrintYearCalendar(today.Year);

    // İki tarih arasındaki farkı hesapla
    stDate date1 = ReadFullDate("\nEnter the first date:");
    stDate date2 = ReadFullDate("Enter the second date:");
    int daysDiff = GetDifferenceInDays(date1, date2, true);
    cout << "Difference (including end day): " << daysDiff << " days\n";

    // Bir tatilin dönüş tarihini hesapla (iş günü olarak)
    short vacationDays = ReadNumber("Enter vacation length (business days):", 1, 365, "Invalid number.");
    stDate returnDate = CalculateVacationReturnDate(today, vacationDays);
    PrintDate("Vacation Return Date (Business Days):", returnDate);
    return 0;
    
}
