import sys,pygame
from pygame.locals import *
from settings import Settings
from ship import  Ship

def run_game ():
    pygame.init()
    ai_settings= Settings()
    screen =pygame.display.set_mode((ai_settings.screen_width ,ai_settings.screen_height))
    pygame.display.set_caption("plane")
    ship = Ship(screen)

    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
        screen.fill(ai_settings.bg_color)
        ship.blitme()
        pygame.display.flip()

run_game()