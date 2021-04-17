from tkinter import *
import tkinter.scrolledtext as scrolledtext
from tkinter import messagebox
import datetime as dt
import winsound

intro_Wind = Tk()
intro_Wind.geometry("550x450")
intro_Wind.title(" ")
intro_Wind.configure(background="#C18778")

def open_mainWind():

    intro_Wind.destroy()
    
    body = Tk()
    body.var = IntVar()
    body.geometry("550x700")
    body.title("BAAF Mini Billing System v.1.0")
    body.configure(background="black")

    body_Hdng = Frame(body, bg="black")
    body_Hdng.pack(side=TOP)

    body_subHdng = Frame(body, bg="black")
    body_subHdng.pack(side=TOP)

    body_Top2 = Frame(body, bg="black")
    body_Top2.pack(side=TOP)

    body_Mid = Frame(body, bg="black")
    body_Mid.pack(side=BOTTOM)

    #----------heading / subheading----------#,
    hdng = Label(body_Hdng, font=('arial', 30, 'bold', 'italic'), text="bow alum abas food-to-go.", bg="black", fg='#E4A3A2', wraplength=500, bd=10)
    hdng.grid(row=0, column=0)

    time_hdng = Label(body_Hdng, font=('arial', 20, 'bold', 'italic'), text=f"{dt.datetime.now():%a, %b %d %Y}", bg="black", fg='#E4A3A2', wraplength=500)
    time_hdng.grid(row=1, column=0)

    subHdng1 = Label(body_subHdng, font=('arial', 15, 'bold', 'italic', 'underline'), text="meals/munchies", bg="black", fg='#E4A3A2')
    subHdng1.grid(row=2, column=0, padx=(50, 15))

    subHdng2 = Label(body_subHdng, font=('arial', 15, 'bold', 'italic', 'underline'), text="chillers", bg="black", fg='#E4A3A2')
    subHdng2.grid(row=2, column=1, padx=(20, 50))

    subHdng3 = Label(body_subHdng, font=('arial', 15, 'bold', 'italic', 'underline'), text="sweeteners", bg="black", fg='#E4A3A2')
    subHdng3.grid(row=2, column=2, padx=(7, 100))
    
    #----------transaction proper----------#
    transact_List = []
    #--------MEAL--------#
    def augment_PF(PF_price):
        TransactBox.insert(INSERT, "PURCHASED: #1 Potato Fries - Php 39\n")
        transact_List.append(PF_price)

    def augment_CB(CB_price):
        TransactBox.insert(INSERT, "PURCHASED: #2 Carbonara - Php 45\n")
        transact_List.append(CB_price)

    def augment_CF(CF_price):
        TransactBox.insert(INSERT, "PURCHASED: #3 Chicken Fillet w/ Rice - Php 55\n")
        transact_List.append(CF_price)

    def augment_BS(BS_price):
        TransactBox.insert(INSERT, "PURCHASED: #4 Burger Steak - Php 45\n")
        transact_List.append(BS_price)
    #--------DRINKS--------#
    def augment_S(S_price):
        TransactBox.insert(INSERT, "PURCHASED: #5 Soda - Php 20\n")
        transact_List.append(S_price)

    def augment_MT(MT_price):
        TransactBox.insert(INSERT, "PURCHASED: #6 Milk Tea - Php 59\n")
        transact_List.append(MT_price)

    def augment_J(J_price):
        TransactBox.insert(INSERT, "PURCHASED: #7 Orange Juice - Php 20\n")
        transact_List.append(J_price)

    def augment_IC(IC_price):
        TransactBox.insert(INSERT, "PURCHASED: #8 Iced Coffee - Php 40\n")
        transact_List.append(IC_price)
    #--------DESSERT--------#
    def augment_AP(AP_price):
        TransactBox.insert(INSERT, "PURCHASED: #9 Apple Pie - Php 20\n")
        transact_List.append(AP_price)

    def augment_CC(CC_price):
        TransactBox.insert(INSERT, "PURCHASED: #10 Chocolate Cake - Php 25\n")
        transact_List.append(CC_price)

    def augment_D(D_price):
        TransactBox.insert(INSERT, "PURCHASED: #11 Matcha Doughnut - Php 15\n")
        transact_List.append(D_price)

    def augment_Sun(Sun_price):
        TransactBox.insert(INSERT, "PURCHASED: #12 Strawberry Sundae - Php 29\n")
        transact_List.append(Sun_price)
    
    def total_Cost():
        if not transact_List:
            checkout_Error = messagebox.showerror("Empty Transaction", "Cannot checkout with zero balance.")
        else:
            PotatoFries.config(state=DISABLED)
            Carbonara.config(state=DISABLED)
            ChickenFillet.config(state=DISABLED)
            BurgerSteak.config(state=DISABLED)
            
            
            Soda.config(state=DISABLED)
            MilkTea.config(state=DISABLED)
            Juice.config(state=DISABLED)
            IcedCoffee.config(state=DISABLED)
            
            ApplePie.config(state=DISABLED)
            ChocoCake.config(state=DISABLED)
            Donut.config(state=DISABLED)
            Sundae.config(state=DISABLED)
            
            PurchaseButton.config(state=DISABLED)
            
            TransactBox.delete('1.0', END)
            
            total_Bill = sum(transact_List)
            
            TransactBox.insert(INSERT, "\n\n\n")
            TransactBox.insert(INSERT, "|------------------------------------------------|\n")
            TransactBox.insert(INSERT, "|            YOUR TOTAL BILL IS:                 |\n")
            TransactBox.insert(INSERT, "                   Php %d.                        \n" % total_Bill)
            TransactBox.insert(INSERT, "                                                  \n")
            TransactBox.insert(INSERT, "          ++ THANK YOU FOR ORDERING               \n")
            TransactBox.insert(INSERT, "|         AND ALWAYS STAY AT HOME!! :) ++        |\n")
            TransactBox.insert(INSERT, "|------------------------------------------------|\n")

    def new_Customer():
        reset_Prompt = messagebox.askyesno("Reset Entries", "Are you sure you want to delete all entries?")
        if reset_Prompt == True:
            TransactBox.delete('1.0', END)
        
            PotatoFries.config(state=NORMAL)
            Carbonara.config(state=NORMAL)
            ChickenFillet.config(state=NORMAL)
            BurgerSteak.config(state=NORMAL)
            
            
            Soda.config(state=NORMAL)
            MilkTea.config(state=NORMAL)
            Juice.config(state=NORMAL)
            IcedCoffee.config(state=NORMAL)
            
            ApplePie.config(state=NORMAL)
            ChocoCake.config(state=NORMAL)
            Donut.config(state=NORMAL)
            Sundae.config(state=NORMAL)
            
            PurchaseButton.config(state=NORMAL)

            transact_List.clear()

    def exit_Prog():
        exit_Prompt = messagebox.askyesno("Exit Program", "Are you sure you want to exit?")
        if exit_Prompt == True:
            winsound.PlaySound(None, winsound.SND_ASYNC)
            body.destroy()
    
    #----------snackz----------#
    PotatoFries = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Potato Fries [Php 39]", activebackground='black', wraplength=100, relief=RAISED, command=lambda: augment_PF(39), height=2, width=13)
    PotatoFries.grid(row=2, column=0, padx=(73, 50), pady=(0, 230))

    Carbonara = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Cheesy Carbonara [Php 45]", activebackground='black', wraplength=115, relief=RAISED, command=lambda: augment_CB(45), height=2, width=13)
    Carbonara.grid(row=2, column=0, padx=(73, 50), pady=(0, 140))

    ChickenFillet = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Chicken Fillet w/ Rice [Php 55]", activebackground='black', wraplength=120, relief=RAISED, command=lambda: augment_CF(55), height=2, width=13)
    ChickenFillet.grid(row=2, column=0, padx=(73, 50), pady=(0, 50))

    BurgerSteak = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Burger Steak [Php 45]", activebackground='black', wraplength=100, relief=RAISED, command=lambda: augment_BS(45), height=2, width=13)
    BurgerSteak.grid(row=2, column=0, padx=(73, 50), pady=(40, 0))

    Soda = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Soda [Php 20]", activebackground='black', wraplength=60, relief=RAISED, command=lambda: augment_S(20), height=2, width=10)
    Soda.grid(row=2, column=1, padx=(0, 250), pady=(0, 230))
    
    MilkTea = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Milk Tea [Php 59]", activebackground='black', wraplength=80, relief=RAISED, command=lambda: augment_MT(59), height=2, width=10)
    MilkTea.grid(row=2, column=1, padx=(0, 250), pady=(0, 140))

    Juice = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Orange Juice [Php 20]", activebackground='black', wraplength=80, relief=RAISED, command=lambda: augment_J(20), height=2, width=10)
    Juice.grid(row=2, column=1,padx=(0, 250), pady=(0, 50))

    IcedCoffee = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Iced Coffee [Php 40]", activebackground='black', wraplength=80, relief=RAISED, command=lambda: augment_IC(40), height=2, width=10)
    IcedCoffee.grid(row=2, column=1, padx=(0, 250), pady=(40, 0))

    ApplePie = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Apple Pie [Php 20]", activebackground='black', wraplength=80, relief=RAISED, command=lambda: augment_AP(20), height=2, width=13)
    ApplePie.grid(row=2, column=1, padx=(50, 0), pady=(0, 230))

    ChocoCake = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Chocolate Cake [Php 25/slice]", activebackground='black', wraplength=100, relief=RAISED, command=lambda: augment_CC(25), height=2, width=13)
    ChocoCake.grid(row=2, column=1, padx=(50, 0), pady=(0, 140))

    Donut = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Matcha Doughnut [Php 15]", activebackground='black', wraplength=115, relief=RAISED, command=lambda: augment_D(15), height=2, width=13)
    Donut.grid(row=2, column=1, padx=(50, 0), pady=(0, 50))

    Sundae = Button(body_Top2, font=('arial', 10), bg='#C18778', text="Strawberry Sundae [Php 29]", activebackground='black', wraplength=120, relief=RAISED, command=lambda: augment_Sun(29), height=2, width=13)
    Sundae.grid(row=2, column=1, padx=(50, 0), pady=(40, 0))


    #----------textbox----------#
    TransactBox = scrolledtext.ScrolledText(body_Mid, font=('consolas', 10, 'bold'), bg='#C18778', fg='black', height=10, width=60, bd=5)
    TransactBox.grid(row=0, padx=(20, 20), pady=(0, 20))


    #----------checkout button----------#
    PurchaseButton = Button(body_Mid, font=('arial', 10, 'bold', 'italic'), bg='#E4A3A2', activebackground='black', text="Checkout", relief=RAISED, command=total_Cost)
    PurchaseButton.grid(row=1, column=0, pady=(0, 100), padx=(0, 150))


    #----------reset / new transaction button----------#
    ResetTransact = Button(body_Mid, font=('arial', 10, 'bold', 'italic'), bg='#E4A3A2', activebackground='black', text="Reset", relief=RAISED, command=new_Customer)
    ResetTransact.grid(row=1, column=0, pady=(0, 100), padx=(20, 0))

    #----------exit program button----------#
    quitTransact = Button(body_Mid, font=('arial', 10, 'bold', 'italic'), bg='#E4A3A2', activebackground='black', text="Exit", relief=RAISED, command=exit_Prog)
    quitTransact.grid(row=1, column=0, pady=(0, 100), padx=(155, 0))


    body.mainloop()

start_Msg = Label(intro_Wind, font=('arial', 30, 'bold', 'italic'), text="BAAF Mini Billing System v1.0", bg="#C18778", fg='black', bd=10, anchor='center', wraplength=400)
start_Msg.pack(pady=(130, 0))

proceed_But = Button(intro_Wind, font=('arial', 20, 'bold', 'italic'), bg='black', fg='#F7CACA', text="open", anchor='center', relief=RAISED, activebackground='black', command=open_mainWind)
proceed_But.pack(pady=(20, 0))

winsound.PlaySound("BLACKPINK - 'FOREVER YOUNG' Perfect Loop (5 Minute Snippet).wav", winsound.SND_FILENAME|winsound.SND_LOOP|winsound.SND_ASYNC)

intro_Wind.mainloop()
