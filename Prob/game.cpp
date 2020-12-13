#include "game.h"

Game::Game(){

    texture[0].loadFromFile("player.jpg");//текстура игрока
    texture[1].loadFromFile("trava.jpg");//текстура травы
    texture[2].loadFromFile("money.png");//текстура монеты
    texture[3].loadFromFile("teleport.jpg");//текстура телепорт
    texture[4].loadFromFile("stone.jpg");//текстура камня
    texture[5].loadFromFile("live.png");//текстура жизни
    texture[6].loadFromFile("vrag.jpg");//текстура врага 
    //sprite(texture);
  
}

void Game::CreateSquare(){
   cout<<"Начать новую игру - 1, старую 0\n";
   int choose;
   cin>> choose;
   safe safe(choose);
/* if(!feof(safe->*outputFile))
{
    cout<<"GGG";
}  */
    if (choose==0)
        safe.check();
    
    
    
    
    sf::RenderWindow window(sf::VideoMode(x*size+22+150, y*size+28), "Game created by Lapina Anastasia");
    
    rect = new sf::RectangleShape *[x];
    for (int i = 0; i < x; i++) {
    	rect[i] = new sf::RectangleShape[y];
    	for (int j = 0; j < y; j++) {
    	//вход
          if(i==0 && j==0){
               square->obj[0][0]->Tip=square->obj[0][0]->i;
               rect[i][j].setFillColor(sf::Color(0, 0, 200));
               rect[i][j].setSize(sf::Vector2f(size, size));
    	       rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
            	continue;
      	   }
          //выход
          if(i==x-1 && j==y-1){
              square->obj[i][j]->Tip=square->obj[i][j]->e;
              rect[i][j].setFillColor(sf::Color(200, 0, 0));
              rect[i][j].setSize(sf::Vector2f(size, size));
    	      rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
              continue;
          }
      	 //монеты
      	 if ((i==3&&j==0) || (i==1&&j==7) || (i==7&&j==5) || (i==5&&j==11)){
             square->obj[i][j]->Tip=square->obj[i][j]->m;
             rect[i][j].setTexture(&texture[2]);
             rect[i][j].setSize(sf::Vector2f(size, size));
    	     rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
             continue;
     	  }
      	 //камни
      	 if ((i==4&&j==2) || (i==7&&j==1) || (i==6&&j==8) || (i==0&&j==11)){ 
             square->obj[i][j]->Tip=square->obj[i][j]->s;
             rect[i][j].setTexture(&texture[4]);
             rect[i][j].setSize(sf::Vector2f(size, size));
    	     rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
             continue;
        }
      	    
      	 //телепорт
       if ((i==3&&j==4) || (i==8 &&j==10)){
      	    square->obj[i][j]->Tip=square->obj[i][j]->t;
            rect[i][j].setTexture(&texture[3]);
            rect[i][j].setSize(sf::Vector2f(size, size));
    	    rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
            continue;
      	 }
      	 //враг
      	if ((i==9&&j==3) || (i==9&&j==6) ||(i==9&&j==9)){
      	    square->obj[i][j]->Tip=square->obj[i][j]->vrag;
            rect[i][j].setTexture(&texture[1]);
            rect[i][j].setSize(sf::Vector2f(size, size));
    	    rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
            continue;
      	 }
      	 
      	     //иначе
             square->obj[i][j]->Tip=square->obj[i][j]->o;
             rect[i][j].setTexture(&texture[1]);	 
             rect[i][j].setSize(sf::Vector2f(size, size));
    	     rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
        }
    }        
    drawPlayer();
    drawEnemy(9,9);
    drawEnemy(9,6);
    drawEnemy(9,3);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                if (event.type == sf::Event::KeyPressed) {
                    //enemy1.go(player.y_now, player.x_now);
                    Move();
	            //закрытие при достижения выхода
    		    if (player.x_now==y-1 && player.y_now==x-1){
    		        GameEnd(&window);
    		        addToFile("WIN"); 
       	        }
    		    //выход, если кончиись жизни
   		    if (player.live==0||player.money<0){
   		       GameEnd(&window);
   		       addToFile("LOST");
       	        }
                 }
        }
        
        window.clear();
        
        Info();
        
        window.draw(money);
        window.draw(moneyInfo);
        window.draw(live);
        window.draw(liveInfo);
         
    	for (int i = 0; i < x; i++)
    		for (int j = 0; j < y; j++)
    			window.draw(rect[i][j]);
    			
        window.display();
    }
}

void Game::Move(){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        clearCell(player.x_now, player.y_now);
    	player.Go(-1, 0);
    	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        clearCell(player.x_now, player.y_now);    			    	
    	player.Go(0, -1);
    	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    	clearCell(player.x_now, player.y_now);
    	player.Go(1, 0);
    	}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        clearCell(player.x_now, player.y_now);
    	player.Go(0, 1);
   }
   //если телепорт
    if (player.tele){
        player.teleport();
    	if (!player.tele){
            clearCell(4, 3);
            square->obj[4][3]->Tip=square->obj[4][3]->o;
            square->obj[8][10]->Tip=square->obj[8][10]->o;
            }
    }
    drawPlayer();
    
    //если монета, то добавляем монету
    if (square->obj[player.y_now][player.x_now]->Tip == 2){
        player.Put_Money();
        square->obj[player.y_now][player.x_now]->Tip =square->obj[player.y_now][player.x_now]->o; 
    }
  		    
    //если камень - уменьшаем жизни
    if (square->obj[player.y_now][player.x_now]->Tip == 1){
    	player.Pull_Live();
        square->obj[player.y_now][player.x_now]->Tip =square->obj[player.y_now][player.x_now]->o; 
    }
    
    if(!enemy1.killed){
    int x_e1 = enemy1.GetX();
    int y_e1 = enemy1.GetY();
    cout <<"!!!\n";
    square->obj[x_e1][y_e1]->Tip=square->obj[x_e1][y_e1]->o;
        for(int z = 0; z<10; z++){
        if ((z!=player.y_now)||(y_e1!=player.x_now))
            clearEnemy(z, y_e1);
        } 
        
        enemy1.go(player.y_now, player.x_now);
    x_e1 = enemy1.GetX();
    drawEnemy(x_e1, y_e1);
    square->obj[x_e1][y_e1]->Tip=square->obj[x_e1][y_e1]->vrag;
   if (enemy1.there){
       // behavior.live();
        player.Pull_Live();
        //cout <<"Yes!!\n";
    }
    }
    
    if(!enemy2.killed){
    int x_e2 = enemy2.GetX();
    int y_e2 = enemy2.GetY();
    square->obj[x_e2][y_e2]->Tip=square->obj[x_e2][y_e2]->o;
        for(int z = 0; z<10; z++){
        if ((z!=player.y_now)||(y_e2!=player.x_now))
            clearEnemy(z, y_e2);
        } 
        
    enemy2.go(player.y_now, player.x_now);
    x_e2 = enemy2.GetX();
    drawEnemy(x_e2, y_e2);
    square->obj[x_e2][y_e2]->Tip=square->obj[x_e2][y_e2]->vrag;
    if (enemy2.there){
        //behavior.money();
        player.Pull_Money();
        //cout <<"Yes!!\n";
    }
    }
    if(!enemy3.killed){
    int x_e3 = enemy2.GetX();
    int y_e3 = enemy3.GetY();
    
    square->obj[x_e3][y_e3]->Tip=square->obj[x_e3][y_e3]->o;
        for(int z = 0; z<10; z++){
        if ((z!=player.y_now)||(y_e3!=player.x_now))
            clearEnemy(z, y_e3);
            square->obj[z][y_e3]->Tip=square->obj[z][y_e3]->o;
        } 
        
    enemy3.go(player.y_now, player.x_now);
    x_e3 = enemy3.GetX();
    drawEnemy(x_e3, y_e3);
    square->obj[x_e3][y_e3]->Tip=square->obj[x_e3][y_e3]->vrag;
    if (enemy3.there){
        //behavior.position();
        player.start();
        //cout <<"Yes3!!\n";
    }
    }
    
    Info_for_safe();
    
}

void Game::Info_for_safe(){
    string mstr = "money = \n "+ std::to_string(player.money) + '\n';
    addToFile(mstr);
    string lstr = "live = \n "+ std::to_string(player.live) + '\n';
    addToFile(lstr);
    string pstr = "p = \n "+ std::to_string(player.x_now) + " " + std::to_string(player.y_now) + '\n';
    addToFile(pstr);
    
    for (int i = 0; i<13; i++){
    for (int j = 0; j<10; j++){
    if (square->obj[j][i]->Tip==square->obj[j][i]->i)
    	//cout <<"i";
        addToFile("i");
    if (square->obj[j][i]->Tip==square->obj[j][i]->e)
    	//cout <<"e";
    	addToFile("e");
    if (square->obj[j][i]->Tip==square->obj[j][i]->o)
    	addToFile("o");
    	//cout <<"o";    	
    if (square->obj[j][i]->Tip==square->obj[j][i]->s)
    	addToFile("s");
    	//cout <<"s"; 
    if (square->obj[j][i]->Tip==square->obj[j][i]->m)
    	addToFile("m");
    	//cout <<"m"; 
    if (square->obj[j][i]->Tip==square->obj[j][i]->t)
    	addToFile("t");
    	//cout <<"t";   
    if (square->obj[j][i]->Tip==square->obj[j][i]->vrag)
    	addToFile("vrag");
    	//cout <<"vrag";   
    	//o, s, m, t, i, e, vrag
    addToFile(" ");	
    	
    }
    addToFile("\n");

    }
    
}

void Game::addToFile(std::string str)
{
    safe safe(0);
    safe.addLog(str);
}

void Game::Info(){
        money.setSize(sf::Vector2f(50, 50));
        money.setPosition(sf::Vector2f(450, 140));
        money.setTexture(&texture[2]);
        
        moneyInfo.setFont(font);
        font.loadFromFile("Ubuntu-Bold.ttf");
        moneyInfo.setString(std::to_string(player.money));
        moneyInfo.setCharacterSize(30);
        moneyInfo.setFillColor(sf::Color(255, 255, 255));
        moneyInfo.setPosition(sf::Vector2f(530, 140));
        
        live.setSize(sf::Vector2f(90, 70));
        live.setPosition(sf::Vector2f(430, 300));
        live.setTexture(&texture[5]); 
        
        liveInfo.setFont(font);
        font.loadFromFile("Ubuntu-Bold.ttf");
        liveInfo.setString(std::to_string(player.live));
        liveInfo.setCharacterSize(30);
        liveInfo.setFillColor(sf::Color(255, 255, 255));
        liveInfo.setPosition(sf::Vector2f(530, 320));
}

void Game::GameEnd(sf::RenderWindow* window){
    window->close();
}

Game::~Game(){
    for (int i = 0; i < x; i++)
    	delete [] rect[i];
    delete [] rect;
    delete square;

}

void Game::drawPlayer(){
        rect[player.y_now][player.x_now].setTexture(&texture[0]);

}

void Game::drawEnemy(int x_e, int y_e){
        rect[x_e][y_e].setTexture(&texture[6]);

}

void Game::clearEnemy(int x_e, int y_e){

	rect[x_e][y_e].setTexture(&texture[1]);
	//cout << "Очислил " << x_e<< "   " <<y_e << "\n";

}

void Game::clearCell(int x_c, int y_c){

	rect[y_c][x_c].setTexture(&texture[1]);

}
