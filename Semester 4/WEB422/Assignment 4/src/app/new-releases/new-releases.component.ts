import { Component, OnInit } from '@angular/core';
import data from '../data/new-releases.json';

@Component({
  selector: 'app-new-releases',
  templateUrl: './new-releases.component.html',
  styleUrls: ['./new-releases.component.css']
})
export class NewReleasesComponent implements OnInit {

  releases: Array<any>  = [];

  constructor() { }

  ngOnInit(): void {
    this.releases = data.albums.items;
  }

}
