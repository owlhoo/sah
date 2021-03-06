#include "konj.h"
#include "../figura.h"

extern bool pojeden_kralj;

Konj::Konj(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;
  if (bela)
    simbol = "\u2658";
  else
    simbol = "\u265e";
}

bool Konj::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << RED BOLD << "Nije moguce izvrsiti potez." << RESET << endl;
    return false;
  }

  if ((abs(pozicija_x - x) == 2 && abs(pozicija_y - y) == 1) ||
      (abs(pozicija_x - x) == 1 && abs(pozicija_y - y) == 2))
  {
    if (prva->tabla[x][y] != nullptr && prva->tabla[x][y]->get_bela() == this->get_bela())
    {
      cout << RED BOLD << "Nije moguce izvrsiti potez. Ne mozete jesti svoje figure." << RESET << endl;
      return false;
    }

    if (prva->tabla[x][y] != nullptr && (prva->tabla[x][y]->get_simbol() == "\u2654" || prva->tabla[x][y]->get_simbol() == "\u265a"))
      pojeden_kralj = true;

    int px = pozicija_x;
    int py = pozicija_y;
    pozicija_x = x;
    pozicija_y = y;
    prva->tabla[x][y] = this;
    prva->tabla[px][py] = nullptr;
    return true;
  }
  else
  {
    cout << RED BOLD << "Nije moguce izvrsiti potez." << RESET << endl;
    return false;
  }
}
