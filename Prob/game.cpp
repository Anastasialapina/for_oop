#include "game.h"

void Game::CreateSquare(){
    sf::RenderWindow window(sf::VideoMode(x*size+22+150, y*size+28), "Game created by Lapina Anastasia");
    texture[0].loadFromFile("player.jpg");//текстура игрока
    texture[1].loadFromFile("trava.jpg");//текстура травы
    texture[2].loadFromFile("money.png");//текстура монеты
    texture[3].loadFromFile("teleport.jpg");//текстура телепорт
    texture[4].loadFromFile("stone.jpg");//текстура камня
    texture[5].loadFromFile("live.png");//текстура жизни
    
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
      	     //иначе
             square->obj[i][j]->Tip=square->obj[i][j]->o;
             rect[i][j].setTexture(&texture[1]);	 
             rect[i][j].setSize(sf::Vector2f(size, size));
    	     rect[i][j].setPosition(sf::Vector2f(size * i + 2*(i+1), size * j + 2*(j+1)));
        }
    }
        
    drawPlayer();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                if (event.type == sf::Event::KeyPressed) {
    			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    			    	clearCell(player.x_now, player.y_now);
    				player.Go(-1, 0);
    				drawPlayer();
    			}
    			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
    			        clearCell(player.x_now, player.y_now);    			    	
    				player.Go(0, -1);
    				drawPlayer();
    			}
    			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    			    	clearCell(player.x_now, player.y_now);
    				player.Go(1, 0);
    				drawPlayer();
    			}
    			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
    			        clearCell(player.x_now, player.y_now);
    				player.Go(0, 1);
    				drawPlayer();
    			}
    		    //если телепорт
    		    if (player.tele){
    			        player.teleport();
    			        if (!player.tele)
    			            clearCell(4, 3);
    	                    }
    	           drawPlayer();
    			    
       	    //закрытие при достижения выхода
    		    if (player.x_now==y-1 && player.y_now==x-1){
  		        window.close();
    		        //cout << "УРА! ПОБЕДА!"<<"\n";
       	        }

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
    		    //выход, если кончиись жизни
   		    if (player.live==0){
      		       window.close();
    		        //cout << "К сожалению, Вы проиграли!"<< "\n";
       	        }
           }
        }
        
        window.clear();
        
        money.setSize(sf::Vector2f(50, 50));
        money.setPosition(sf::Vector2f(450, 140));
        money.setTexture(&texture[2]);
        window.draw(money);
        
         moneyInfo.setFont(font);
         font.loadFromFile("Ubuntu-Bold.ttf");
         moneyInfo.setString(std::to_string(player.money));
         moneyInfo.setCharacterSize(30);
         moneyInfo.setFillColor(sf::Color(255, 255, 255));
         moneyInfo.setPosition(sf::Vector2f(530, 140));
         window.draw(moneyInfo);
        
        live.setSize(sf::Vector2f(90, 70));
        live.setPosition(sf::Vector2f(430, 300));
        live.setTexture(&texture[5]); 
        window.draw(live);
        
         liveInfo.setFont(font);
         font.loadFromFile("Ubuntu-Bold.ttf");
         liveInfo.setString(std::to_string(player.live));
         liveInfo.setCharacterSize(30);
         liveInfo.setFillColor(sf::Color(255, 255, 255));
         liveInfo.setPosition(sf::Vector2f(530, 320));
         window.draw(liveInfo);
        //SquareInterator *s;
    	for (int i = 0; i < x; i++)
    		for (int j = 0; j < y; j++)
    			window.draw(rect[i][j]);
    			
        window.display();
    }
    
    for (int i = 0; i < x; i++)
    	delete [] rect[i];
    delete [] rect;
    delete square;
}


void Game::drawPlayer(){
        rect[player.y_now][player.x_now].setTexture(&texture[0]);

}

void Game::clearCell(int x_c, int y_c){

	rect[y_c][x_c].setTexture(&texture[1]);

}
