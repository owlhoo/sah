#include "pijun.h"
#include "../figura.h"

Pijun::Pijun(int x, int y, bool b, Tabla *prva) : Figura(b, x, y)
{
  this->prva = prva;

  if (bela)
    simbol = "\u2659";
  else
    simbol = "\u265f";
}

void Pijun::pomeri(int x, int y)
{
  if (x < 0 || x > 7 || y < 0 || y > 7)
  {
    cout << "Nije moguce izvrsiti potez (polje se ne nalazi na tabli)." << endl;
    return;
  }

  if (bela)
  {

    // Kad jede (krece se ukoso)
    if (pozicija_x - x == 1 && abs(y - pozicija_y) == 1)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
      return;
    }

    if (x > pozicija_x || y != pozicija_y)
    {
      cout << "Nije moguce izvrsiti potez (pijun ne moze ici unazad niti levo-desno)." << endl;
      return;
    }

    if (x == pozicija_x - 1 && prva->tabla[x][y] == nullptr)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
    }
    else if (x == pozicija_x - 2 && pozicija_x == 6 && prva->tabla[x][y] == nullptr && prva->tabla[x - 1][y] == nullptr)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
    }
    else
      cout << "Nije moguce izvrsiti potez" << endl;
  }
  else // Ako je crni
  {

    // Kad jede (krece se ukoso)
    if (x - pozicija_x == 1 && abs(y - pozicija_y) == 1)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
      return;
    }

    if (x < pozicija_x || y != pozicija_y)
    {
      cout << "Nije moguce izvrsiti potez (pijun ne moze ici unazad niti levo-desno)." << endl;
      return;
    }
    if (x == pozicija_x + 1 && prva->tabla[x][y] == nullptr)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
    }
    else if (x == pozicija_x + 2 && pozicija_x == 1 && prva->tabla[x][y] == nullptr && prva->tabla[x + 1][y] == nullptr)
    {
      int px = pozicija_x;
      int py = pozicija_y;
      pozicija_x = x;
      pozicija_y = y;
      prva->tabla[x][y] = this;
      prva->tabla[px][py] = nullptr;
    }
    else
      cout << "Nije moguce izvrsiti potez" << endl;
  }
}
