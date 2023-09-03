from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

driver = webdriver.Chrome()

def EnterTextBoxWait(Id, text):
    element = wait.until(EC.presence_of_element_located((By.ID, Id))) #Ожидаем пока найдём id
    element.send_keys(text) #Отправляем ввод данных в тестовое поле

def ClickButtonById(Id):
    element = wait.until(EC.presence_of_element_located((By.ID, Id)))
    element.click()  #Кликаем

url = "https://www.roblox.com/login" 

driver.get(url)
wait = WebDriverWait(driver, 10)  # Ожидаем максимум 10 секунд загрузки веб страницы

#Начать цикл здесь
EnterTextBoxWait("login-username", "Rustcog0950")
EnterTextBoxWait("login-password", "fY9BvmWt1g7jysN")
ClickButtonById("login-button")
url = "https://www.roblox.com/home"
wait.until(EC.url_to_be(url)) #Ожидаем пока перекинет на новый url 

element = wait.until(EC.presence_of_element_located((By.ID, "nav-settings")))
element.click() 
time.sleep(1)
element = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "logout-menu-item")))
element.click() 
time.sleep(1)