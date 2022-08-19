/*********************************************************************************
* WEB422 – Assignment 06
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of this
* assignment has been copied manually or electronically from any other source (including web sites) or
* distributed to other students. *
* Name: ___YiHsun Lee___ Student ID: __129713202__ Date: __2022/July/30__ *
* Angular App (Deployed) Link: _____https://comfy-starburst-7e6acb.netlify.app/____ *
* User API (Heroku) Link: ____https://limitless-tundra-16641.herokuapp.com_____
* ********************************************************************************/

import { Component, OnInit } from '@angular/core';
import { NavigationStart, Router } from '@angular/router';
import { AuthService } from './auth.service';
import User from './User';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit {
  title = 'web422-a4';
  searchString: string = "";
  token: User | null = null;

  constructor(private router: Router, private auth: AuthService) {}

  ngOnInit(): void {
    this.router.events.subscribe((event) => {
      if(event instanceof NavigationStart){
        this.token = this.auth.readToken();
      }
    })
  }

  handleSearch(){
    this.router.navigate(['/search'], {queryParams: {q: this.searchString}})
    this.searchString = "";
  }

  logOut(){
    localStorage.clear();
    this.router.navigate(['/login']);
  }
}
