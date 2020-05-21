import pygame.font

class Scoreboard():
    def __init__(self, screen):
       self.score = 0
       self.screen = screen
       self.screen_rect = screen.get_rect()

       self.text_color = (30, 30, 30)
       self.font = pygame.font.SysFont(None, 48)

       self.prep_score()

    def show_score(self):
        self.screen.blit(self.score_image, self.score_rect)

    def prep_score(self, num=0):
        self.score += num
        score_str = str(self.score)
        self.score_image = self.font.render(score_str, True, self.text_color, (200, 200, 200))
        self.score_rect = self.score_image.get_rect()
        self.score_rect.right = self.screen_rect.right-20
        self.score_rect.bottom = self.screen_rect.bottom
        return self.score