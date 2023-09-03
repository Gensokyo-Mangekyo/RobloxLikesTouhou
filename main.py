from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time


def EnterTextBoxWait(Id, text):
    element = wait.until(EC.presence_of_element_located((By.ID, Id))) #Ожидаем пока найдём id
    element.send_keys(text) #Отправляем ввод данных в тестовое поле

def ClickButtonById(Id):
    element = wait.until(EC.presence_of_element_located((By.ID, Id)))
    element.click()  #Кликаем

driver = webdriver.Chrome()


url = "https://www.roblox.com/login" 

# Переход по URL
driver.get(url)
wait = WebDriverWait(driver, 10)  # Ожидаем максимум 10 секунд загрузки веб страницы

# Ввод данных в текстовое поле
EnterTextBoxWait("login-username", "r1l3g7x4o7b4e2")
EnterTextBoxWait("login-password", "s0qvdyemtc")
ClickButtonById("login-button")
url = "https://www.roblox.com/home"
wait.until(EC.url_to_be(url)) #Ожидаем пока перекинет на новый url 
RobloxGame = "https://www.roblox.com/games/13484061921/Eternal-Dream"
driver.get(RobloxGame)
wait.until(EC.url_to_be(RobloxGame)) #Ожидаем пока перекинет на новый url 
element = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "icon-favorite")))
element.click() 

element = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "icon-like")))
element.click() 

while True:
    time.sleep(100)
